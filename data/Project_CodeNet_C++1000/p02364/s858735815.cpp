#include <queue>
#include <string>
#include <vector>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

// ------ Class ------ //
class Graph2 {
public:
	// ------ Variables ------ //
	static const long long INF = 1000000000000000000;
	int V, E; vector<vector<pair<int, long long> > > G;

	// ------ Constructors ------ //
	Graph2() : V(0), E(0), G(vector<vector<pair<int, long long> > >()) {}
	Graph2(int v) : V(v), E(0), G(vector<vector<pair<int, long long> > >(v)) {}
	Graph2(vector<vector<pair<int, long long> > > g) : V(g.size()), G(g) { for (int i = 0; i < g.size(); i++) E += g[i].size(); }

	// ------ Basic Functions ------ //
	int size() { return V; }
	void add1(int v1, int v2, long long w) { G[v1].push_back(make_pair(v2, w)); E++; }
	void add2(int v1, int v2, long long w) { add1(v1, v2, w); add1(v2, v1, w); }

	// ------ Operators ------ //
	friend bool operator==(const Graph2& g1, const Graph2& g2) { return g1.G == g2.G; }
	friend bool operator!=(const Graph2& g1, const Graph2& g2) { return g1.G != g2.G; }
	vector<pair<int, long long> > operator[](int x) { return G[x]; }

	// ------ Algorithms ------ //
	long long minspan() {
		vector<long long> d(V, INF);
		vector<bool> used(V, false);
		priority_queue<pair<long long, int> > que;
		for (int i = 0; i < V; i++) d[i] = INF;
		d[0] = 0; que.push(make_pair(0, 0));
		while (!que.empty()) {
			pair<long long, int> pa = que.top(); que.pop();
			int u = pa.second; used[u] = true;
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i].first;
				if (d[v] > G[u][i].second && !used[v]) {
					d[v] = G[u][i].second; que.push(make_pair(-d[v], v));
				}
			}
		}
		long long sum = 0;
		for (int i = 0; i < V; i++) sum += d[i];
		return sum;
	}
};

// ------ Main ------ //
int V, E, s, t, w;
int main() {
	scanf("%d%d", &V, &E);
	Graph2 G(V);
	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &s, &t, &w);
		G.add2(s, t, w);
	}
	printf("%d\n", G.minspan());
	return 0;
}