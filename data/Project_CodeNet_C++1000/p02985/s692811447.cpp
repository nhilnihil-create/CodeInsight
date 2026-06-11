#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 1e5 + 5;
const ll LINF = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, k, f[N], c[N];
vector <int> G[N];
ll powmod(ll a, ll b)
{
	ll ans = 1;
	while(b)
	{
		if(b&1) ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}
void dfs(int u, int fa)
{
	int pre = 0;
	f[u] = fa;
	for(int v : G[u])
	{
		if(v==fa) continue;
		dfs(v, u);
		c[v] = c[pre] + 1;
		pre = v;
	}
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n >> k;
 	for(int i=1; i<n; i++) 
 	{
 		int u, v;
 		cin >> u >> v;
 		G[u].pb(v); G[v].pb(u);
 	}
 	c[0] = -1;
 	dfs(1, 0);
 	ll ans = 1;
 	for(int i=1; i<=n; i++)
 	{
 		if(f[i]) c[i]++;
 		if(f[f[i]]) c[i]++;
 		if(k-c[i]<0) ans = 0;
 		ans = ans*(k-c[i])%mod;
 	}
 	cout << ans;
	return 0;
}
