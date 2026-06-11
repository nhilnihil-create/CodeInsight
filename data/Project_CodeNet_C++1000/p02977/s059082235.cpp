#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;

    if (__builtin_popcount(n) == 1) {
        std::cout << "No" << std::endl;
        return 0;
    }

    int r = n % 4;
    std::deque<std::pair<int, int>> q;
    auto add_edge = [&](int i, int j) {
        q.emplace_back(i, j);
    };

    if (r == 1 || r == 3) {
        add_edge(1, 2);
        add_edge(2, 3);
        add_edge(3, 1 + n);
        add_edge(1 + n, 2 + n);
        add_edge(2 + n, 3 + n);

        for (int i = 1; i * 4 + 1 <= n; i++) {
            add_edge(i * 4, i * 4 + 1);
            add_edge(i * 4 + 1, 1);
            add_edge(1, i * 4 + n);
            add_edge(i * 4 + n, i * 4 + 1 + n);
        }

        for (int i = 1; i * 4 + 3 <= n; i++) {
            add_edge(i * 4 + 2, i * 4 + 3);
            add_edge(i * 4 + 3, 1);
            add_edge(1, i * 4 + 2 + n);
            add_edge(i * 4 + 2 + n, i * 4 + 3 + n);
        }
    } else if (r == 0) {
        int s = 1 << __builtin_ctz(n),
            t = n ^ s;
        std::vector<int> a { s, t };
        for (int i = 1; i < n; i++) {
            if (i != s && i != t) a.push_back(i);
        }
        for (int i = 1; i < n - 1; i++) {
            add_edge(a[i - 1], a[i]);
            add_edge(a[i - 1] + n, a[i] + n);
        }
        add_edge(a.back(), a.front() + n);
        add_edge(n, s);
        add_edge(t, n + n);
    } else {
        add_edge(1, 2);
        add_edge(2, 3);
        add_edge(3, 1 + n);
        add_edge(1 + n, 2 + n);
        add_edge(2 + n, 3 + n);

        for (int i = 1; i * 4 + 1 < n - 2; i++) {
            add_edge(i * 4, i * 4 + 1);
            add_edge(i * 4 + 1, 1);
            add_edge(1, i * 4 + n);
            add_edge(i * 4 + n, i * 4 + 1 + n);
        }

        for (int i = 1; i * 4 + 3 < n - 2; i++) {
            add_edge(i * 4 + 2, i * 4 + 3);
            add_edge(i * 4 + 3, 1);
            add_edge(1, i * 4 + 2 + n);
            add_edge(i * 4 + 2 + n, i * 4 + 3 + n);
        }

        add_edge(n, n - 1);
        add_edge(n - 1, 3);
        add_edge(3, n + n);
        add_edge(n + n, n - 1 + n);

        add_edge(n - 2, n - 1);
        add_edge(2, n - 2 + n);
    }

    std::cout << "Yes\n";
    for (const auto &e : q) std::cout << e.first << " " << e.second << std::endl;

    return 0;
}
