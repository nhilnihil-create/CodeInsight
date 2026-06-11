#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

struct UnionFind {
	vector<int> par, siz;
	UnionFind(int n): par(n), siz(n, 1) {
		rep(i,n) par[i] = i;
	}
	int find(int x) {
		return par[x] == x ? x: par[x] = find(par[x]);
	}
	bool unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}
	int size(int x) {
		return siz[find(x)];
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	UnionFind uf(n);
	rep(i,m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		uf.unite(a, b);
	}
	int ans = 0;
	rep(i,n) {
		ans = max(ans, uf.size(i));
	}
	cout << ans << endl;
}