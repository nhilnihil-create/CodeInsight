#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using i64 = long long;

auto sieve(long long n) {
    using i64 = long long;
    std::vector<i64> ps, lp(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!lp[i]) {
            lp[i] = i;
            ps.push_back(i);
        }
        for (unsigned j = 0; j < ps.size() && ps[j] <= lp[i] && i * ps[j] <= n; j++) {
            lp[i * ps[j]] = ps[j];
        }
    }
    return lp;
}

int main() {
    int n;
    std::cin >> n;
    const auto lp = sieve(1010101);

    int g = 0;
    std::vector<int> v, ps(1010101);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        g = std::gcd(g, a);
        while (a > 1) {
            const int p = lp[a];
            ps[p]++;
            while (a % p == 0) a /= p;
        }
    }

    const bool pc = std::all_of(ps.begin(), ps.end(), [](const int e) { return e < 2; });
    std::cout << (pc ? "pairwise coprime" : g == 1 ? "setwise coprime" : "not coprime") << std::endl;

    return 0;
}
