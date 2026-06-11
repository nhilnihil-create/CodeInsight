#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
struct UnionFind {
	vector<int> par;
	UnionFind(int N) : par(N, -1) {}
	void init(int N) { par.assign(N, -1); }
	int root(int x) {
		if (par[x] < 0) return x;
		return par[x] = root(par[x]);
	}
	bool issame(int x, int y) { return root(x) == root(y); }
	bool merge(int x, int y) {
		x = root(x), y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}
	int size(int x) { return -par[root(x)]; }
};
template <typename T>
struct Edge {
	int a, b;
	T cost;
	bool operator<(const Edge<T> &o) { return cost < o.cost; }
};
ll kruskal(const int &n, vector<Edge<ll>> &a) {
	sort(a.begin(), a.end());
	UnionFind Tree(n);
	ll res = 0;
	for (auto p : a) {
		if (Tree.issame(p.a, p.b)) continue;
		res += p.cost;
		Tree.merge(p.a, p.b);
	}
	return res;
}
int main() {
	int v, e;
	scanf("%d%d", &v, &e);
	vector<Edge<ll>> a(e);
	for (int i = 0; i < e; i++) scanf("%d%d%lld", &a[i].a, &a[i].b, &a[i].cost);
	ll ans = kruskal(v, a);
	printf("%lld\n", ans);
	return 0;
}
