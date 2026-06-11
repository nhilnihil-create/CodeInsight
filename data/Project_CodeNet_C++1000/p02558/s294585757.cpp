#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
	int N;
	vector<int> parent;
	vector<int> size_r;
	int num_of_sets;

	UnionFind(int N) : N(N), parent(N), size_r(N, 1), num_of_sets(N) {
		for (int i = 0; i < N; ++i) parent[i] = i;
	}

	int root(int x) {
		if (parent[x] == x) return x;
		return parent[x] = root(parent[x]);
	}

	bool merge(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (size_r[x] < size_r[y]) swap(x, y);
		parent[y] = x;
		size_r[x] += size_r[y];
		size_r[y] = 0;
		num_of_sets--;
		return true;
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	int size(int x) {
		return size_r[root(x)];
	}
};

int main() {
	int n, Q;
	cin >> n >> Q;
	UnionFind uf(n);
	for (int q = 0; q < Q; q++) {
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);
		if (t == 0) {
			uf.merge(u, v);
		} else {
			if (uf.same(u, v)) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}