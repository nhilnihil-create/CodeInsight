#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#define il inline
#define re register
#define fo(i,j,k) for(register int i=j;i<=k;i++)
#define do(i,j,k) for(register int i=j;i>=k;i--) 
#define inf 0x7fffffff
typedef long long ll;
using namespace std;
il ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f*x;	
}
/*int h[200010],v[200010],dis[200010];
struct edge
{
	int v,w,next;
}e[200010*2];
il void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=h[u];
	h[u]=cnt;
}*/
ll n,k,ans;
ll dp[100010];
const ll mod=1e9+7;
ll cal(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=(ret*a)%mod;
        a=(a*a)%mod;
        b>>=1LL;
    }
    return ret;
}
int main()
{
    n=read(),k=read();
    for(re ll i=k;i>=1;i--)
    {
        ll num=k/i;
        dp[i]=cal(num,n);
        for(ll j=2*i;j<=k;j+=i)
        {
            dp[i]=(dp[i]-dp[j]+mod)%mod;
        }
        ans=(ans+dp[i]*i)%mod;
    }
    printf("%lld\n",ans);
}