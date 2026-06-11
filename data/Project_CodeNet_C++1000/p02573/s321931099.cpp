#include <iostream>
#include <vector>

class union_find {
	int M;
	std::vector<int> parent, sz;

public :
	const int N;

	union_find(const int& n) : N(n), M(n) {parent.resize(N, -1); sz.resize(N, 1);}

	int root(const int& i) {
		if (parent[i] == -1) return i;
		return parent[i] = root(parent[i]);
	}

	inline bool is_united(const int& i, const int& j) {return (root(i) == root(j));}

	bool unite(int i, int j) {
		if (is_united(i, j)) return false;
		if (size(i) < size(j)) std::swap(i, j);
		i = root(i); j = root(j);
		parent[j] = i;
		sz[i] += sz[j];
		M--;
		return true;
	}

	inline const int& size(const int& i) {return sz[root(i)];}
	inline const int& count_trees()const{return M;}
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