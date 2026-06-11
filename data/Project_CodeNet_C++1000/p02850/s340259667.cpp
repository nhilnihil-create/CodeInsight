#include <bits/stdc++.h>
using namespace std;

int n, k;
vector < vector < pair < int, int > > > g;
vector < pair < int, int > > edges;
vector < int > ans;

void dfs (int u, int p, int clr) {
	int cur = 1;
	for (auto pr: g[u]) {
		int v = pr.first, i = pr.second;
		if (cur == clr)
			++cur;
		if (v != p) {
			ans[i] = cur;
			dfs(v, u, cur);
			++cur;
		}
	}
}

void ckmax (int &x, int a) {
	x = max(x, a);
}

signed main () {
	cin >> n;
	g.resize(n + 1);
	edges.resize(n - 1);
	ans.resize(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> edges[i].first >> edges[i].second;
		g[edges[i].first].push_back(make_pair(edges[i].second, i));
		g[edges[i].second].push_back(make_pair(edges[i].first, i));
	}
	k = 0;
	for (int i = 1; i <= n; ++i)
		ckmax(k, int(g[i].size()));
	dfs(1, -1, -1);
	cout << k << '\n';
	for (int i = 0; i < n - 1; ++i)
		cout << ans[i] << '\n';
}
