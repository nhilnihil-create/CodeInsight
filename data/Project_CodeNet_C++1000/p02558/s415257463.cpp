#include <iostream>
#include <vector>
#include <numeric>
using i64 = long long;

class UF {
    std::vector<int> par, rank;

    public:
    UF(int size) : par(size), rank(size) {
        std::iota(par.begin(), par.end(), 0);
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (rank[x] < rank[y]) par[x] = y;
        else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
};

int main() {
    int n, q;
    std::cin >> n >> q;

    UF uft(n + 1);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t) std::cout << uft.same(u, v) << '\n';
        else uft.unite(u, v);
    }

    return 0;
}
