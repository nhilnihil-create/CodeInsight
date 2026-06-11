#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct edge {
	int from, to;
	int cost;
	edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

using edges = vector<edge>;
using graph = vector<edges>;

void add_edge(graph& G, int s, int t, int c) {
	G[s].emplace_back(s, t, c);
}

template <typename C, const C inf>
vector<C> bellman_ford(const graph& G, int s) {
	int n = G.size();
	vector<C> d(n, inf);
	d[s] = C();
	bool update;
	for (int i = 0; i < n; i++) {
		update = false;
		for (auto& es : G) {
			for (auto e : es) {
				if (d[e.from] == inf || d[e.to] <= d[e.from] + e.cost) continue;
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
	}
	return update ? vector<C>() : d;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int V, E, r;
	cin >> V >> E >> r;
	graph G(V);
	for (int i = 0; i < E; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		add_edge(G, s, t, d);
	}
	auto d = bellman_ford<int, INF>(G, r);
	if (d.empty()) {
		puts("NEGATIVE CYCLE");
	}
	else {
		for (int i = 0; i < V; i++) {
			if (d[i] == INF)
				puts("INF");
			else
				printf("%d\n", d[i]);
		}
	}
	return 0;
}