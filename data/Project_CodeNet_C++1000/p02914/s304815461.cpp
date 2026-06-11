#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    i64 x = 0;
    for (auto &e : a) {
        std::cin >> e;
        x ^= e;
    }

    for (auto &e : a) e &= ~x;

    for (int i = 60, index = 0; i >= 0; i--) {
        int mi = index;
        i64 me = -1;
        for (int j = index; j < n; j++) {
            if ((a[j] & (1ll << i)) && a[j] > me) {
                me = a[j];
                mi = j;
            }
        }

        if (me == -1) continue;

        std::swap(a[index], a[mi]);

        mi = index++;

        for (int j = 0; j < n; j++) {
            if (j != mi && (a[j] & (1ll << i))) a[j] ^= a[mi];
        }
    }

    i64 m = 0;
    for (int i = 0; i < n; i++) m ^= a[i];

    std::cout << x + m * 2 << std::endl;

    return 0;
}
