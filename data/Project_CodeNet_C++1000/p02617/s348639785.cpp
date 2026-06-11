#include <iostream>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;

    i64 ret = 0;
    for (i64 i = 1; i <= n; i++) ret += i * (n - i + 1);

    for (int i = 1; i < n; i++) {
        i64 u, v;
        std::cin >> u >> v;
        if (u > v) std::swap(u, v);
        ret -= u * (n - v + 1);
    }

    std::cout << ret << std::endl;

    return 0;
}
