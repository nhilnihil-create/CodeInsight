#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const long long Maxn=100;
long long f[Maxn],a[Maxn];
long long n;
inline long long read()
{
	long long s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int main()
{
	n=read();
	for(long long i=1;i<=n;++i)
	a[i]=read();
	f[1]=1000;
	for(long long i=2;i<=n;++i)
	f[i]=max(f[i-1],f[i-1]/a[i-1]*a[i]+f[i-1]%a[i-1]);
	printf("%lld\n",f[n]);
	return 0;
}