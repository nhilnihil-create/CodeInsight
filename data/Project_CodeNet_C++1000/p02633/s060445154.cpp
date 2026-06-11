#include<bits/stdc++.h>
using namespace std;

int x;

inline int qr()
{
	int w=1,x=0;char a=0;
	while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<1)+(x<<3)+(a^48);a=getchar();}
	return x*w;
}

int main()
{
	x=qr();
	int k=360;
	while(k%x!=0)
		k+=360;
	cout<<k/x<<endl;
	return 0;
} 