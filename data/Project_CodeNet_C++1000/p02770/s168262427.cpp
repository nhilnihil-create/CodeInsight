#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int k, q;
    std::cin >> k >> q;
    std::vector<int> a(k);
    for (auto &e : a) std::cin >> e;

    while (q--) {
        int n, mod;
        i64 x;
        std::cin >> n >> x >> mod;
        x %= mod;
        --n;

        int ret = 0;
        for (int i = 0; i < k; i++) {
            const int co = n / k + (n % k > i);
            if (a[i] % mod == 0) ret += co;
            else x = x + 1ll * co * (a[i] % mod);
        }

        std::cout << n - (ret + x / mod) << std::endl;
    }

    return 0;
}
