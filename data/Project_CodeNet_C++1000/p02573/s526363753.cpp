#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> g;

vector<bool> visited;

int dfs(int v) {
	int size = 1;
	visited[v] = true;
	for (int u: g[v])
		if (!visited[u])
			size += dfs(u);
	return size;
}

void solve_test() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < n; i++) g[i].clear();
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	visited.resize(n);
	for (int i = 0; i < n; i++) visited[i] = false;

	vector<int> component_sizes;
	for (int i = 0; i < n; i++)
		if (!visited[i])
			component_sizes.push_back(dfs(i));

	cout << *max_element(component_sizes.begin(), component_sizes.end()) << '\n';
}

int32_t main() {
	int T; 
	// cin >> T;
	T = 1;
	while (T--)
		solve_test();

	return 0;
}
