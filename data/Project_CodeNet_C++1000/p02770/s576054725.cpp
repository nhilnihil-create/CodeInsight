#include<bits/stdc++.h>
using namespace std;
#define next Next
#define gc getchar
#define int long long
const int N=1e6+5;
int n,m,k,ans,inv[N],a[N],b[N];
char s[N];
//char buf[1<<21],*p1=buf,*p2=buf;
//inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
inline int read()
{
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}
signed main()
{
	n=read();m=read();
	for(int i=0;i<n;i++)a[i]=read();
	while(m--)
	{
		int A=read(),B=read(),mod=read();
		int ans=0,S=0;
		for(int i=0;i<n;i++)
		{
			b[i]=a[i]%mod;
			if(b[i]==0)b[i]=mod;
			S+=b[i];
		}
		ans=B;
		ans+=S*((A-1)/n);
		for(int i=0;i<(A-1)%n;i++)ans+=b[i];
		printf("%lld\n",A-1-(ans/mod-B/mod));
	}
	return 0;
}