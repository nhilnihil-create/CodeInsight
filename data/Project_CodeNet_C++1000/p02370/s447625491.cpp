#include <bits/stdc++.h>
using namespace std;

using graph = vector<vector<int>>;


void dfs(int v, const graph& G, vector<int>& res, vector<int>& used) {
	used[v] = 1;
	for (auto to : G[v]) if (used[to] == 0) {
		dfs(to, G, res, used);
	}
	res.push_back(v);
}

vector<int> topo_sort(const graph& G) {
	int V = G.size();
	vector<int> ide(V);
	for (int i = 0; i < V; i++) {
		for (auto to : G[i]) {
			ide[to]++;
		}
	}
	vector<int> res;
	vector<int> used(V);
	for (int i = V - 1; i >= 0; i--) {
		if (ide[i] == 0) {
			dfs(i, G, res, used);
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	int V, E;
	cin >> V >> E;
	graph G(V);
	for (int i = 0, s, t; i < E; i++) {
		cin >> s >> t;
		G[s].push_back(t);
	}
	auto res = topo_sort(G);
	for (int i = 0; i < V; i++) {
		cout << res[i] << endl;
	}
	return 0;
}