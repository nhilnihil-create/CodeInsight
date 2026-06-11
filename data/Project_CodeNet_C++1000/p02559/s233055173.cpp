#include <iostream>
#include <vector>
#include <functional>

template<typename T> struct segment_tree {
	int N;
	std::vector<T> V;
	std::function<T(T, T)> F;
	T E;

	segment_tree(std::vector<T>& a, std::function<T(T, T)> f, T e) : F(f), E(e) {
		int m = 1;
		while (m < a.size()) m *= 2;
		V.resize(N = m * 2, E);
		for (int i = 0; i < a.size(); i++) V[m + i] = a[i];
		for (int i = m - 1; i > 0; i--) V[i] = F(V[i * 2], V[i * 2 + 1]);
	}

	segment_tree(int n, std::function<T(T, T)> f, T e) : F(f), E(e) {
		int m = 1;
		while (m < n) m *= 2;
		V.resize(N = m * 2, E);
	}

	void point_update(int i, T x, std::function<T(T, T)> update) {
		int idx = N / 2 + i;
		V[idx] = update(V[idx], x);
		while (idx /= 2) V[idx] = F(V[idx * 2], V[idx * 2 + 1]);
	}

	T range_fold(int L, int R, int idx = 1, int l = 0, int r = -1) {
		if (r == -1) r = N / 2;
		if (L <= l && r <= R) return V[idx];
		if (r <= L || R <= l) return E;
		return F(range_fold(L, R, idx * 2, l, (l + r) / 2), range_fold(L, R, idx * 2 + 1, (l + r) / 2, r));
	}
};

int main() {
	int n, q;
	std::cin >> n >> q;
	std::vector<long long> a(n);
	for (int i = 0; i < n; i++) std::cin >> a[i];

	segment_tree<long long> sg(a, [](long long a, long long b){return a + b;}, 0);
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 0) {
			int p; long long x;
			std::cin >> p >> x;
			sg.point_update(p, x, [](long long a, long long b){return a + b;});
		} else {
			int l, r;
			std::cin >> l >> r;
			std::cout << sg.range_fold(l, r) << '\n';
		}
	}

	return 0;
}