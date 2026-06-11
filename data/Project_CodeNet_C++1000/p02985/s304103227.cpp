#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 1e9 + 7;

int64_t mul_mod (int64_t a, int64_t b) {
	return (a * b) % mod;
}

int n;
int64_t k;
vector < vector < int > > g;
vector < int > mul;
set < int > untouchable;

void dfs (int u, int p) {
	int cnt = 0;
	for (int v: g[u]) {
		if (v != p) {
			mul[v] = k - 1 - cnt - int((untouchable.find(v) == untouchable.end()));
			dfs(v, u);
			++cnt;
		}
	}
}

signed main () {
	cin >> n >> k;
	g.resize(n + 1);
	mul.assign(n + 1, -1);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	mul[1] = k;
	for (int v: g[1]) 
		untouchable.insert(v);
	dfs(1, -1);
	int64_t ans = 1;
	for (int i = 1; i <= n; ++i)
		ans = mul_mod(ans, int64_t(mul[i]));
	cout << ans << '\n';
}
