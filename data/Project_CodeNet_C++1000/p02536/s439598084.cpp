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
	int N, M;
	cin >> N >> M;
	UnionFind uf(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		uf.unite(a - 1, b - 1);
	}
	cout << uf.size() - 1 << "\n";

	return 0;
}
