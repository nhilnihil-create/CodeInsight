#include <iostream>
#include <atcoder/dsu>

int main() {
    int n, q;
    std::cin >> n >> q;
    atcoder::dsu d(n);
    for (int i = 0; i < q; ++i) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) d.merge(u, v);
        else {
            std::cout << d.same(u, v) << "\n";
        }
    }
}