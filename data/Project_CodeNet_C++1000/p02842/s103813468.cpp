#include <bits/stdc++.h>

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 1; i <= 47000; i++) {
        if ((int) std::floor(1.08 * i) == n) {
            std::cout << i;
            return 0;
        }
    }

    std::cout << ":(";

    return 0;
}