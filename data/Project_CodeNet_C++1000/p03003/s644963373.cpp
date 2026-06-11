#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<17, mod = 1e9 + 7, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vi s, t;
int n ,m;
ll dp[1<<11][1<<11], p[1<<11][1<<11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	s.resize(n);for(auto&i:s) cin>>i;
	t.resize(m);for(auto&i:t) cin>>i;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(s[i]==t[j]) {
				dp[i][j] = 1;
				if(i&&j) dp[i][j] = (dp[i][j]+p[i-1][j-1])%mod;
			}
			p[i][j] = (4ll*mod + (i?p[i-1][j]:0ll)+(j?p[i][j-1]:0ll)-(i&&j?p[i-1][j-1]:0ll)+dp[i][j])%mod;
		}
	}
	cout << ++p[n-1][m-1]%mod;
	return 0;
}
