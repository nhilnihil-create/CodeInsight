#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;

int main() {
    constexpr i64 mod = 1000000007;
    int n;
    std::cin >> n;
    if (n <= 2) {
        std::cout << 0 << std::endl;
        return 0;
    }

    i64 ret = 0;
    std::vector<i64> v(n + 1);
    v[n] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 3; j <= n; j++) ret = (ret + v[j]) % mod;
        std::vector<i64> next(n + 1);
        i64 t = v[n];
        for (int i = n - 3; i >= 0; i--) {
            next[i] = t;
            t = (t + v[i + 2]) % mod;
        }
        std::swap(v, next);
    }

    std::cout << ret << std::endl;

    return 0;
}
