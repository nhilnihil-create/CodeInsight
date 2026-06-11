#include<bits/stdc++.h>
using namespace std;
#define reg register
#define ll long long
#define mo 1000000007
inline ll read()
{
	ll x=0,w=0;char ch=getchar();
	while(!isdigit(ch))w|=ch=='-',ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}
int n,x,y,a[200005],vis[200005],gs1,gs2;
ll jc[200005],f[200005],d[200005],c[200005],e[200005],b[200005];
char s[200005];
int main()
{
    n=read();scanf("%s",s+1);jc[1]=1;reg int i,j;
    for(i=2;i<=n;++i)jc[i]=1ll*jc[i-1]*i%mo;
    if(s[1]=='W'){cout<<0<<"\n";return 0;}
    for(i=1;i<=n*2;++i)if(s[i]=='B')a[i]=1;f[1]=1;
    for(i=1;i<=n*2;++i)if(a[i]!=a[i-1])b[i]=1;
    for(i=2;i<=2*n;++i)
    {
        if(b[i]==0){if(f[i-1]==1)f[i]=2;else f[i]=1;}
        else{if(f[i-1]==1)f[i]=1;else f[i]=2;}
    }
    for(i=1;i<=2*n;++i)
    {
        if(f[i]==1)c[++gs1]=i;
        else d[++gs2]=i;
    }
    if(f[2*n]!=2||gs1!=n||gs2!=n){puts("0");return 0;}
    for(i=n,j=n;i>=1;--i)
    {
        while(d[j]>c[i])--j;
        e[i]=n-j;
    }
    reg ll ans=1;
    for(i=n;i>=1;--i)
    {
        ans=ans*(e[i]-(n-i))%mo;
    }
    cout<<ans*jc[n]%mo<<"\n";
	return 0;
}
