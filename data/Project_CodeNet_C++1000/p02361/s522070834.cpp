#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// ------ Class ------ //
template <class T> class Graph2 {
public:
	// ------ Variables ------ //
	static const T INF = numeric_limits<T>::max();
	int V, E; vector<vector<pair<int, T> > > G;

	// ------ Constructors ------ //
	Graph2() : V(0), E(0), G(vector<vector<pair<int, T> > >()) {}
	Graph2(int v) : V(v), E(0), G(vector<vector<pair<int, T> > >(v)) {}
	Graph2(vector<vector<pair<int, T> > > g) : V(g.size()), G(g) { for (int i = 0; i < g.size(); i++) E += g[i].size(); }

	// ------ Basic Functions ------ //
	int size() { return V; }
	void add1(int v1, int v2, T w) { G[v1].push_back(make_pair(v2, w)); E++; }
	void add2(int v1, int v2, T w) { add1(v1, v2, w); add1(v2, v1, w); }

	// ------ Operators ------ //
	bool operator==(const Graph2& g) const { return G == g.G; }
	bool operator!=(const Graph2& g) const { return G != g.G; }
	vector<pair<int, T> > operator[](int x) { return G[x]; }

	// ------ Algorithms ------ //
	vector<T> dist(int s) {
		priority_queue<pair<T, int> > que; que.push(make_pair(0, s));
		vector<T> d(V, INF); d[s] = 0;
		while (!que.empty()) {
			pair<T, int> t = que.top(); que.pop();
			int u = t.second;
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i].first; T e = G[u][i].second;
				if (d[v] > d[u] + e) {
					d[v] = d[u] + e;
					que.push(make_pair(-d[v], v));
				}
			}
		}
		return d;
	}
};
// ------ Main ------ //
int V, E, r, s, t, w;
int main() {
	cin >> V >> E >> r;
	Graph2<int> G(V);
	for(int i = 0; i < E; i++) {
		cin >> s >> t >> w;
		G.add1(s, t, w);
	}
	vector<int> d = G.dist(r);
	for(int i = 0; i < V; i++) {
		if(d[i] != Graph2<int>::INF) cout << d[i] << endl;
		else cout << "INF" << endl;
	}
}