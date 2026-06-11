#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
template <class T> class Graph2 {
public:
	static const T INF = numeric_limits<T>::max();
	int V, E; vector<vector<pair<int, T> > > G;
	Graph2() : V(0), E(0), G(vector<vector<pair<int, T> > >()) {}
	Graph2(int v) : V(v), E(0), G(vector<vector<pair<int, T> > >(v)) {}
	Graph2(vector<vector<pair<int, T> > > g) : V(g.size()), G(g) { for (int i = 0; i < g.size(); i++) E += g[i].size(); }
	int size() { return V; }
	void add1(int v1, int v2, T w) { G[v1].push_back(make_pair(v2, w)); E++; }
	void add2(int v1, int v2, T w) { add1(v1, v2, w); add1(v2, v1, w); }
	bool operator==(const Graph2& g) const { return G == g.G; }
	bool operator!=(const Graph2& g) const { return G != g.G; }
	vector<pair<int, T> > operator[](int x) { return G[x]; }
	T minspan() {
		vector<T> d(V, INF);
		vector<bool> used(V, false);
		priority_queue<pair<T, int> > que;
		for (int i = 0; i < V; i++) d[i] = INF;
		d[0] = 0; que.push(make_pair(0, 0));
		while (!que.empty()) {
			pair<T, int> pa = que.top(); que.pop();
			int u = pa.second; used[u] = true;
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i].first;
				if (d[v] > G[u][i].second && !used[v]) {
					d[v] = G[u][i].second; que.push(make_pair(-d[v], v));
				}
			}
		}
		T sum = 0;
		for (int i = 0; i < V; i++) sum += d[i];
		return sum;
	}
};
int V, E, s, t, w;
int main() {
	scanf("%d%d", &V, &E);
	Graph2<int> G(V);
	for(int i = 0; i < E; i++) {
		scanf("%d%d%d", &s, &t, &w);
		G.add2(s, t, w);
	}
	printf("%d\n", G.minspan());
}