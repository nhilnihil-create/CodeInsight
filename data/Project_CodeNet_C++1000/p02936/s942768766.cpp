#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<vector<int>> g;
vector<ll> f, ans;

void dfs(int v, int p) {
	for (auto nv : g[v]) {
		if (nv == p) continue;
		ans[nv] += ans[v];
		dfs(nv, v);
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	g.assign(n, vector<int>());
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ans.assign(n, 0);
	rep(i, q) {
		int p, x;
		cin >> p >> x;
		p--;
		ans[p] += x;
	}
	dfs(0, -1);
	rep(i, n) {
		cout << ans[i];
		if (i == n - 1) cout << endl;
		else cout << " ";
	}
	return 0;
}