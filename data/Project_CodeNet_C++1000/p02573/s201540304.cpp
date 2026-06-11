#include <iostream>
#include <vector>

struct union_find {
	int N, M;
	std::vector<int> parent, sz;

	union_find(int n) : N(n), M(n) {
		parent.resize(N);
		for (int i = 0; i < N; i++) parent[i] = i;
		sz.resize(N, 1);
	}

	int root(int i) {
		if (parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}

	bool is_united(int i, int j) {return (root(i) == root(j));}

	int size(int i) {return sz[root(i)];}
	std::pair<int, int> size() {return {N, M};}

	bool unite(int i, int j) {
		if (is_united(i, j)) return false;
		if (size(i) < size(j)) std::swap(i, j);
		i = root(i); j = root(j);
		parent[j] = i;
		sz[i] += sz[j];
		M--;
		return false;
	}
};

int main() {
	int n, m;
	std::cin >> n >> m;
	union_find uf(n);
	while (m--) {
		int a, b;
		std::cin >> a >> b;
		uf.unite(a - 1, b - 1);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) ans = std::max(ans, uf.size(i));
	std::cout << ans << '\n';

	return 0;
}