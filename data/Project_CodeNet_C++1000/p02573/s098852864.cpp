/*in the name of Allah the most beneficent the most merciful.*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 1e18
#define MIN -1e18
#define MOD 1000000007
//#define mod2 20071027
//#define MOD 998244353
// #define base 100001
//#define mod 1000074259
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define TC(c) printf("Case %lld:\n", ++c)
#define out(x) cout << #x << " -> " << x << endl;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE   freopen("input.txt", "r", stdin);  freopen("out.txt", "w", stdout);
using namespace std;
const int N = 300010;
ll n, m,res=1,par[N],sz[N];
ll fp(ll a){
	if(par[a]==a) return a;
	return par[a]=fp(par[a]);
}
int solve() {
	in2(n,m);
	for(int i=1;i<=n;i++) {
		sz[i]=1;
		par[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		ll u, v;
		in2(u,v);
		ll pu = fp(u);
		ll pv = fp(v);
		if(pu!=pv){
			par[pv]=pu;
			sz[pu]+=sz[pv];
			res=max(res, sz[pu]);
			sz[pv]=0;
		}
	}
	printf("%lld\n", res);
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return solve();
}