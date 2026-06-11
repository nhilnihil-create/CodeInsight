#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
class Graph1 {
public:
	// ------Basics ------ //
	static const int INF = 2147483647;
	int V, E; vector<vector<int> > G;
	Graph1() : V(0), E(0), G(vector<vector<int> >()) {}
	Graph1(int v) : V(v), E(0), G(vector<vector<int> >(v)) {}
	Graph1(vector<vector<int> > g) : V(g.size()), G(g) { for (int i = 0; i < g.size(); i++) E += g[i].size(); }
	int size() { return V; }
	void add1(int v1, int v2) { G[v1].push_back(v2); E++; }
	void add2(int v1, int v2) { add1(v1, v2); add1(v2, v1); }
	friend bool operator==(const Graph1& g1, const Graph1& g2) { return g1.G == g2.G; }
	friend bool operator!=(const Graph1& g1, const Graph1& g2) { return g1.G != g2.G; }
	vector<int> operator[](int x) { return G[x]; }

	// ------ Algorithms ------ //
	vector<int> tsort() {
		int n = G.size();
		vector<int> ret, vis(n);
		function<bool(int)> dfs = [&](int v) {
			vis[v] = true;
			for (auto &e : G[v]) if (!vis[e] && !dfs(e)) return false;
			ret.push_back(v);
			return true;
		};
		for (int i = 0; i < n; i++) if (!vis[i] && !dfs(i)) return {};
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
int V, E, s, t;
int main() {
	scanf("%d%d", &V, &E);
	Graph1 G(V);
	for(int i = 0; i < E; i++) {
		scanf("%d%d", &s, &t);
		G.add1(s, t);
	}
	vector<int> v = G.tsort();
	for(int i = 0; i < v.size(); i++) cout << v[i] << endl;
	return 0;
}