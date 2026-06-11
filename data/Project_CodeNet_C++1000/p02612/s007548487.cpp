#include<bits/stdc++.h>
#define N 1000005
using namespace std;

int n,m;

inline int qr()
{
	int x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

int main()
{
	n=qr();
	while(n>0)
		n=n-1000;
	cout<<abs(n)<<endl;
	return 0;
} 