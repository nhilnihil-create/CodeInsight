#include <bits/stdc++.h>
using namespace std;
struct unionFind {
	vector<int> ps;
	unionFind(int n) : ps(n, -1) {
	}
	int root(int x) {
		if (ps[x] < 0)
			return x;
		else
			return ps[x] = root(ps[x]);
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y)
			return;
		if (-ps[x] < -ps[y])
			swap(x, y);
		ps[x] += ps[y];
		ps[y] = x;
		return;
	}
	int size(int x) {
		return -ps[root(x)];
	}
};
int main() {
	int n, q;
	cin >> n >> q;
	unionFind tr(n);
	for (int i = 0; i < q; i++) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0) {
			tr.unite(u, v);
		} else {
			cout << tr.same(u, v) << endl;
		}
	}
	return 0;
}