#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int Maxn=2010;
const int inf=2147483647;
const int mod=1000000007;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int f[Maxn];
int main()
{
	int S=read();
	f[0]=1;f[1]=f[2]=0;
	for(int i=3;i<=S;i++)
	for(int j=3;j<=i;j++)
	f[i]=(f[i]+f[i-j])%mod;
	printf("%d",f[S]);
}
