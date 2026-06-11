#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
int n,cnt[70];
ll a[100100],p[70];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

ll readll()
{
    ll x=0;int f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

void insert(ll x)
{
	per(i,60,0)
	{
		if ((x>>i)&1)
		{
			if (!p[i]) {p[i]=x;return;}
			else x^=p[i];
		}
	}
}

ll query()
{
	ll ans=0;
	per(i,60,0) if ((ans^p[i])>ans) ans^=p[i];
	return ans;
}

int main()
{
	n=read();
	rep(i,1,n) 
	{
		a[i]=readll();
		rep(j,0,60) if ((a[i]>>j)&1) cnt[j]++;
	}
	ll ans=0;
	rep(i,0,60)
		if (cnt[i]&1)
		{
			ans+=(1ll<<i);
			rep(j,1,n) 
				if ((a[j]>>i)&1) a[j]^=(1ll<<i);
		}
	rep(i,1,n) insert(a[i]);
	ans+=query()*2;
	printf("%lld",ans);
	return 0;
}
