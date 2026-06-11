#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int used[10000];

void dfs(int v, const Graph& G, vector<int>& res) {
	used[v] = 1;
	for (auto to : G[v]) if (used[to] == 0) {
		dfs(to, G, res);
	}
	res.push_back(v);
}

int main()
{
	int V, E;
	cin >> V >> E;
	Graph G(V);
	vector<int> ide(V);
	for (int i = 0, s, t; i < E; i++) {
		cin >> s >> t;
		G[s].push_back(t);
		ide[t]++;
	}
	vector<int> res;
	for (int i = V - 1; i >= 0; i--) {
		if (ide[i] == 0) {
			dfs(i, G, res);
		}
	}
	reverse(res.begin(), res.end());
	for (int i = 0; i < V; i++) {
		cout << res[i] << endl;
	}
	return 0;
}