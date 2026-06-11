#include <bits/stdc++.h>

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h, w;
    std::cin >> h >> w;

    if (h <= 1 || w <= 1) {
        std::cout << 1;
        return 0;
    }

    int64_t ans = 1LL * h * w;

    std::cout << (ans + 1) / 2;

    return 0;
}