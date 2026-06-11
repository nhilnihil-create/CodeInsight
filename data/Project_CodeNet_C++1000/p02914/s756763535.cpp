#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
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

ll v[65],a[maxn],n,cnt[65],ans;

inline void ins(ll x)
{
	for(ll i=60;i>=0;i--)
	{
		if(x&(1ll<<i))
		{
			if(v[i]) x^=v[i];
			else {v[i]=x; break;}
		}
	}
}

inline ll qm()
{
	ll tmp=0;
	for(int i=60;i>=0;i--) if((tmp^v[i])>tmp) tmp^=v[i];
	return tmp;
}

int main()
{
	n=read(); rep(i,1,n) a[i]=read();
	rep(x,0,60) rep(j,1,n) if(a[j]&(1ll<<x)) cnt[x]++;
	per(i,60,0)
	{
		if(cnt[i]&1)
		{
			ans+=(1ll<<i);
			rep(j,1,n) if(a[j]&(1ll<<i)) a[j]^=(1ll<<i);
		}
	}
	rep(i,1,n) ins(a[i]); printf("%lld\n",ans+2*qm());
	return 0;
}