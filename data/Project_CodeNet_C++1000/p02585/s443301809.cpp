#include <vector>

struct union_find {
    using size_type = std::size_t;
private :
    size_type _size;
    std::vector<int> node;
public :
    union_find (size_type n) : node(n, -1), _size(n) { }

    bool unite (size_type x, size_type y) {
        if ((x = root(x)) == (y = root(y))) return false;
        if (node[x] > node[y]) std::swap(x, y);
        node[x] += node[y];
        node[y] = x;
        _size--;
        return true;
    }

    bool same (int x, int y) {
        return (root(x) == root(y));
    }

    size_type root (size_type x) {
        if (node[x] < 0) return x;
        return node[x] = root(node[x]);
    }

    size_type size (size_type x) {
        return (size_type(-node[root(x)]));
    }

    constexpr const size_type &size () const noexcept {
        return _size;
    }

};

#include <iostream>
#include <vector>
#include <cassert>

using usize = std::size_t;
constexpr long long INF = (1LL << 60);

template<class T>
void chmax (T &a, const T &b) {
	if (a < b) a = b;
}

int main() {
	usize n, k;
	std::cin >> n >> k;
	std::vector<usize> p(n);
	std::vector<long long> c(n);
	for (auto &e : p) std::cin >> e;
	for (auto &e : c) std::cin >> e;
	
	union_find uf(n);
	std::vector<usize> sz(n);
	std::vector<long long> sum[n];
	std::vector<long long> loop(n, 0);
	for (usize i = 0; i < n; i++) uf.unite(i, --p[i]);
	for (usize i = 0; i < n; i++) {
		sz[i] = uf.size(i);
		sum[i].assign(sz[i] + 1, 0);
		loop[uf.root(i)] += c[i];
	}

	long long ans = -INF;
	for (usize s = 0; s < n; s++) {
		loop[s] = loop[uf.root(s)];
		for (usize v = s, i = 0; i < sz[s]; i++, v = p[v]) if (k >= i + 1) {
			sum[s][i + 1] = sum[s][i] + c[p[v]];
			usize t = (k - i - 1) / sz[s];
			chmax(ans, sum[s][i + 1] + std::max<long long>(0LL, loop[s] * t));
		}
	}
	
	std::cout << ans << '\n';
	
	return 0;
}