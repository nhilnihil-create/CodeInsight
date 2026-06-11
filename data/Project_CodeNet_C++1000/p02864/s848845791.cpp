#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
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
int n,m,h[310];
ll f[310][310];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int main()
{
	n=read();m=read();
	m=n-m;
	rep(i,1,n) h[i]=read();
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	rep(i,1,n)
	{
		rep(j,1,min(i,m))
		{
			rep(k,0,i-1)
				f[i][j]=min(f[i][j],f[k][j-1]+max(0,h[i]-h[k]));
		}
	}
	ll ans=1e18;
	rep(i,1,n) ans=min(ans,f[i][m]);
	if (ans>=1e18) ans=0;
	printf("%lld",ans);
	return 0;
}