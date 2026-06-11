#include <queue>
#include <vector>
#include <iostream>
using namespace std;

// ------ Class ------ //
class Graph1 {
public:
	// ------ Variables ------ //
	static const int INF = 1000000000;
	int V, E; vector<vector<int> > G;

	// ------ Constructors ------ //
	Graph1() : V(0), E(0), G(vector<vector<int> >()) {}
	Graph1(int v) : V(v), E(0), G(vector<vector<int> >(v)) {}
	Graph1(vector<vector<int> > g) : V(g.size()), G(g) { for (int i = 0; i < g.size(); i++) E += g[i].size(); }

	// ------ Basic Functions ------ //
	int size() { return V; }
	void add1(int v1, int v2) { G[v1].push_back(v2); E++; }
	void add2(int v1, int v2) { add1(v1, v2); add1(v2, v1); }

	// ------ Operators ------ //
	friend bool operator==(const Graph1& g1, const Graph1& g2) { return g1.G == g2.G; }
	friend bool operator!=(const Graph1& g1, const Graph1& g2) { return g1.G != g2.G; }
	vector<int> operator[](int x) { return G[x]; }

	// ------ Algorithms ------ //
	vector<int> dist(int s) {
		queue<int> que; que.push(s);
		vector<int> d(V, INF); d[s] = 0;
		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (int i = 0; i < G[u].size(); i++) {
				if (d[G[u][i]] == INF) {
					d[G[u][i]] = d[u] + 1;
					que.push(G[u][i]);
				}
			}
		}
		return d;
	}
};

// ------ Main ------ //
int n, u, k, v;
int main() {
	cin >> n; Graph1 g(n);
	for(int i = 0; i < n; i++) {
		cin >> u >> k;
		for(int j = 0; j < k; j++) cin >> v, g.add1(u - 1, v - 1);
	}
	vector<int> d = g.dist(0);
	for(int i = 0; i < n; i++) cout << i + 1 << ' ' << (d[i] != Graph1::INF ? d[i] : -1) << endl;
}