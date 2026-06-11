#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e18
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,k,a[maxn],f[maxn];

inline bool jud(ll x)
{
	ll tmp=k;
	for(int i=1;i<=n;i++)
	{
		ll p=f[n-i+1],q=x/p;
		if(a[i]>q) tmp-=(a[i]-q);
	}
	if(tmp>=0) return true; return false;
}

int main()
{
	n=read(); k=read();
	rep(i,1,n) a[i]=read(); rep(i,1,n) f[i]=read();
	sort(a+1,a+n+1); sort(f+1,f+n+1);
	ll l=0,r=inf,ans=inf;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(jud(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}