#include <iostream>
using i64 = long long;

int main() {
    constexpr i64 mod = 1000000007;
    int n;
    std::cin >> n;
    i64 a = 1, b = 1, t = 1;
    for (int i = 0; i < n; i++) {
        t = t * 10 % mod;
        a = a * 9 % mod;
        b = b * 8 % mod;
    }

    std::cout << (t + 2 * mod - 2 * a + b) % mod << std::endl;

    return 0;
}
