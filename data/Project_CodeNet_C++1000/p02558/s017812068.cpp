#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

struct UnionFind {
private:
	vector<int> uf;
	size_t sz;

public:
	UnionFind(size_t Size) {
		uf.assign(Size, -1);
		sz = Size;
	}

	int find(int x) { return (uf[x] < 0) ? x : uf[x] = find(uf[x]); }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -uf[find(x)]; }
	int size() { return sz; }

	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) { return; }
		--sz;

		if (uf[y] < uf[x]) { swap(x, y); }
		uf[x] += uf[y];
		uf[y] = x;
	}
};

int main() {
	int N, Q;
	cin >> N >> Q;
	UnionFind uf(N);
	vector<int> ans;
	for (int i = 0; i < Q; ++i) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t) { ans.emplace_back(uf.same(u, v)); }
		else { uf.unite(u, v); }
	}

	for (auto v : ans) { cout << v << "\n"; }

	return 0;
}
