#include <atcoder/fenwicktree>
#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;
    atcoder::fenwick_tree<long long> fw(n);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        fw.add(i, a);
    }
    for (int i = 0; i < q; ++i) {
        int t, x, y;
        std::cin >> t >> x >> y;
        if (t == 0) fw.add(x, y);
        else std::cout << fw.sum(x, y) << "\n";
    }
    return 0;
}
