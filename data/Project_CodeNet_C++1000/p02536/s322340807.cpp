#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
const double ep=1e-7;
const int mod=998244353;
const int INF=0x3f3f3f3f;
const double pi=acos(-1);
#define debug1 puts("?");
#define debug(x) cout<<"##"<<(x)<<endl;
#define mk make_pair
#define PII pair<int,int>
#define PIII pair<int,PII >
#define PIII1 pair<PII,int>
#define PIL pair<int,ll>
#define PLL pair<ll,ll>
#define eb emplace_back
#define fi first
#define se second
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define dep(i,a,b) for(register int i=(a);i>=(b);--i)
#define sd(x) scanf("%d",&(x))
#define slld(x) scanf("%lld",&(x))
#define sdd(x,y) scanf("%d%d",&(x),&(y))
#define sc(s) scanf("%s",(s))
#define pd(x) printf("%d\n",(x))
#define plld(x) printf("%lld\n",(x))
#define pdk(x) printf("%d ",(x))
#define plldk(x) printf("%lld ",(x))
#define pdd(x,y) printf("%d %d\n",(x),(y))
typedef long long ll;
int pre[maxn],be[maxn];
int n,m,cnt;
int Find(int x)
{
	return x==pre[x]?x:pre[x]=Find(pre[x]);
}
void mix(int x,int y)
{
	int fx=Find(x),fy=Find(y);
	pre[fx]=fy;
}
void solve()
{
	sdd(n,m);
	rep(i,1,n)pre[i]=i;
	rep(i,1,m)
	{
		int x,y;
		sdd(x,y);
		mix(x,y);
	}
	rep(i,1,n)be[Find(i)]++;
	rep(i,1,n)if(be[i])cnt++;
	pd(cnt-1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
//	sd(T);
	while(T--)solve();
} 