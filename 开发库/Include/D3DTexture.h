#ifndef D3D_TEXTURE_HEAD_FILE
#define D3D_TEXTURE_HEAD_FILE

#pragma once

#include "D3DDevice.h"
#include "GameEngineHead.h"

//////////////////////////////////////////////////////////////////////////////////

//��ɫ����
#define COLOR_INVALID				D3DCOLOR_XRGB(0,0,0)				//��Ч��ɫ
#define COLOR_TRANSPARENT			D3DCOLOR_XRGB(255,0,255)			//͸����ɫ

//////////////////////////////////////////////////////////////////////////////////
//���ؽṹ
struct tagD3DXCOLORVertex
{
	FLOAT							x, y, z;							//����
	DWORD							color;								//��ɫ
};

//ͼ�νṹ
struct tagD3DXCOLORRHWVertex
{
	FLOAT							x, y, z, rhw;						//����
	DWORD							color;								//��ɫ
};

//����ṹ
struct tagD3DTextureVertex
{
	D3DXVECTOR3						Position;							//��������
	FLOAT							tu,tv;								//��������
};

//�����ʽ
#define D3DFVF_TEXTURE				(D3DFVF_XYZ|D3DFVF_TEX1)			//�����ʽ
#define D3DFVF_COLOR				(D3DFVF_XYZ|D3DFVF_DIFFUSE)			//�����ʽ
#define D3DFVF_COLORRHW				(D3DFVF_XYZRHW|D3DFVF_DIFFUSE)		//�����ʽ

//////////////////////////////////////////////////////////////////////////////////

//��������
class GAME_ENGINE_CLASS CD3DTexture
{
	//ͼƬ��Ϣ
public:
	CSize							m_ImageSize;						//ͼƬ��С
	CSize							m_MemorySize;						//�ڴ��С

	//�ӿڱ���
protected:
	IDirect3DTexture9 *				m_pITexture;						//�����ӿ�
	IDirect3DVertexBuffer9 *		m_pIVertexBuffer;					//���㻺��

	//��������
public:
	//���캯��
	CD3DTexture();
	//��������
	virtual ~CD3DTexture();

	//��ȡ����
public:
	//��������
	IDirect3DTexture9 * GetTexture() { return m_pITexture; }
	//�������
	IDirect3DVertexBuffer9 * GetVertexBuffer() { return m_pIVertexBuffer; }

	//ͼƬ��Ϣ
public:
	//�����ж�
	bool IsNull();
	//��������
	INT GetWidth() { return m_ImageSize.cx; }
	//�����߶�
	INT GetHeight() { return m_ImageSize.cy; }

	//��������
public:
	//��������
	bool Destory();
	//��������
	bool CreateImage(CD3DDevice * pD3DDevice, INT nWidth, INT nHeight);

	//���ܺ���
public:
	//��������
	bool LoadImage(CD3DDevice * pD3DDevice, HINSTANCE hInstance, LPCTSTR pszResource, DWORD dwColorKey);
	//��������
	bool LoadImage(CD3DDevice * pD3DDevice, HINSTANCE hInstance, LPCTSTR pszResource, LPCTSTR pszTypeName);
	//��������
	bool LoadImage(CD3DDevice * pD3DDevice, LPCTSTR pszTextureName,BOOL bCreateCache);

	//�滭����
public:
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest);
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource);
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, INT nSourceWidth, INT nSourceHeight);

	//�滭����
public:
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, BYTE cbAlpha);
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, BYTE cbAlpha);
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, INT nSourceWidth, INT nSourceHeight, BYTE cbAlpha);

	//�滭����
public:
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest);
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource);
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, INT nSourceWidth, INT nSourceHeight);


	//�滭����
public:
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest, BYTE cbAlpha);
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, BYTE cbAlpha);
	//�滭ͼƬ
	bool DrawImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, INT nSourceWidth, INT nSourceHeight, BYTE cbAlpha);


	//-------------------------------------------------------------------------------------
	//��ɫ����
public:
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest);
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource);
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, INT nSourceWidth, INT nSourceHeight);

	//�滭����
public:
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, BYTE cbAlpha);
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, BYTE cbAlpha);
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, INT nSourceWidth, INT nSourceHeight, BYTE cbAlpha);

	//�滭����
public:
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest);
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource);
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, INT nSourceWidth, INT nSourceHeight);

	//�滭����
public:
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest, BYTE cbAlpha);
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, BYTE cbAlpha);
	//�滭��ɫͼƬ
	bool DrawColourFilterImage(CD3DDevice * pD3DDevice, CPoint ptRotationOffset, FLOAT fRadian, CHAR chDirection, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, INT nXSource, INT nYSource, INT nSourceWidth, INT nSourceHeight, BYTE cbAlpha);

	//�滭����
public:
	//�滭ͼƬ
	static bool DrawImage(CD3DDevice * pD3DDevice, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight, DWORD* dwData, INT nImageWidth, INT nImageHeight);

	//�ڲ�����
protected:
	//��ȡ��Դ
	bool GetResourceInfo(HINSTANCE hInstance, LPCTSTR pszResource, LPCTSTR pszTypeName, tagResourceInfo & ResourceInfo);

	//��������
public:
	//���λ��
	VOID SetWindowPos(tagD3DTextureVertex * pTextureVertex, INT nXDest, INT nYDest, INT nDestWidth, INT nDestHeight);
	//������ͼ
	VOID SetTexturePos(CD3DDevice * pD3DDevice, tagD3DTextureVertex * pTextureVertex, INT nXSource, INT nYSource, INT nSourceWidth, INT nSourceHeight);

	//�ڲ�����
public:
	//�滭����
	void DrawImage( CD3DDevice * pD3DDevice, D3DXMATRIX* MatrixWorld );
};

//////////////////////////////////////////////////////////////////////////////////

#endif