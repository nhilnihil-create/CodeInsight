#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main() {
    int64_t N, Q;
    std::cin >> N >> Q;

    atcoder::dsu d(N);
    for (int64_t i = 0; i < Q; i++) {
        int64_t t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        } else {
            std::cout << d.same(u, v) << std::endl;
        }
    }
}