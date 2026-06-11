#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
struct UnionFind {
	vector<int> par;
	UnionFind(int n) : par(n, -1) {}
	void init(int n) { par.assign(n, -1); }
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
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	UnionFind tree(n);
	while (q--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a)
			cout << (tree.issame(b, c) ? 1 : 0) << endl;
		else
			tree.merge(b, c);
	}
	return 0;
}