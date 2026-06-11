#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
const ll INF=1ll<<58;
#define MAXN 200011
ll a[MAXN];
ll n,m,v,k,ans=0;
bool check(ll x)
{
	if(x>=a[n-k+1])return 1;
	if(x+m<a[n-k+1])return 0;
	ll c1=0,c2=0, p=0,r=0;
	for(ll i=1;i<=n;++i)
		if(a[i]<=x)++c1;
		else if(a[i]>a[n-k+1])++c2;
		else
		{
			r+=(m+x-a[i]);
			if(r>=m)//r+(m+x-a[i])>=m
			{
				++p;
				r-=m;
			}
		}
	return c2<k&&c1+c2+p>=v;
}
int main()
{
	n=read(),m=read(),v=read(),k=read(),ans=0;
	for(ll i=1;i<=n;++i)std::cin>>a[i];
	std::sort(a+1,a+n+1);
	ll l=1,r=n;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(a[mid]))r=mid;
		else l=mid+1;
	}
	for(ll i=1;i<=n;++i)ans+=(a[i]>=a[l]);
	printf("%lld",ans);
	return 0;
}