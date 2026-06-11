#include <iostream>
#include <vector>

class union_find {
	const int N; // the number of nodes
	int M; // the number of trees
	std::vector<int> parent, sz;

public :
	union_find(const int& n) : N(n), M(n), parent(n, -1), sz(n, 1) {}

	const int& root(const int& k) {return ((parent[k] == -1)?k:(parent[k] = root(parent[k])));}

	bool is_united(const int& i, const int& j) {return (root(i) == root(j));}

	bool unite(int i, int j) {
		i = root(i); j = root(j);
		if (i == j) return false;
		if (sz[i] < sz[j]) std::swap(i, j);
		sz[i] += sz[j];
		parent[j] = i;
		M--;
		return true;
	}

	const int& count_trees() const {return M;}

	const int& size(const int& k) {return sz[root(k)];}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N, M;
	std::cin >> N >> M;
	union_find uf(N);

	while (M--) {
		int A, B;
		std::cin >> A >> B;
		uf.unite(A - 1, B - 1);
	}
	std::cout << uf.count_trees() - 1 << '\n';
}