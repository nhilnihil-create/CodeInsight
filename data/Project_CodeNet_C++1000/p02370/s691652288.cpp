#include "bits/stdc++.h"
using namespace std;
using LL=long long;

const int INF = 1'000'000'000;
const long long INFLL = 1'000'000'000'000'000'000;

using Weight=int;
struct Edge {
	int to; Weight cost;
	Edge(int _to, Weight _cost) :to(_to), cost(_cost) {}
};
bool operator>(const Edge& e1, const Edge& e2) { return e1.cost > e2.cost; }
struct Edge2 { int u, v; Weight cost; };
using Graph=vector<vector<Edge>>;


vector<int> TopologicalSort(const Graph& graph) {
	int V = graph.size();
	vector<bool> visited(V);
	vector<int> ret;
	function<void(int)> dfs = [&](int u) {
		if (visited[u])return;
		visited[u] = true;
		for (auto& i : graph[u])dfs(i.to);
		ret.push_back(u);
	};
	for (int i = 0; i < V; i++)dfs(i);
	reverse(ret.begin(), ret.end());
	return ret;
}


int main() {
	int v, e; cin >> v >> e;
	Graph g(v);
	for (int i = 0; i < e; i++) {
		int s, t; cin >> s >> t;
		g[s].emplace_back(t, 1);
	}
	for (auto aa : TopologicalSort(g))
		cout << aa << endl;
}
