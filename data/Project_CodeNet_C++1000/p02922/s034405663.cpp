#include <bits/stdc++.h>

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    std::cin >> a >> b;

    int outlets = 1;
    int ans = 0;

    while (outlets < b) {
        outlets = outlets - 1 + a;
        ++ans;
    }

    std::cout << ans;

    return 0;
}
