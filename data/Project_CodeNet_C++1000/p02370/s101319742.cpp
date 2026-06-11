#include <bits/stdc++.h>
using namespace std;
using graph = vector<vector<int>>;

vector<int> topo_sort(const graph& G) {
	int n = G.size();
	vector<int> used(n), idx; idx.reserve(n);
	function<void(int)> dfs = [&](int v) {
		used[v] = true;
		for (int w : G[v]) if (!used[w]) dfs(w);
		idx.push_back(v);
	};
	for (int i = n - 1; i >= 0; i--) {
		if (!used[i]) dfs(i);
	}
	reverse(idx.begin(), idx.end());
	return idx;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	graph G(n);
	for (int i = 0; i < m; i++) {
		int s, t;
		cin >> s >> t;
		G[s].push_back(t);
	}
	auto ts = topo_sort(G);
	for (int i = 0; i < n; i++) {
		printf("%d\n", ts[i]);
	}
	return 0;
}

