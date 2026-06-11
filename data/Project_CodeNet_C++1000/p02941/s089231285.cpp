#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (auto &e : a) std::cin >> e;
    for (auto &e : b) std::cin >> e;
    std::set<std::pair<int, int>> s;
    for (int i = 0; i < n; i++) s.emplace(-b[i], i);

    i64 ret = 0;
    while (!s.empty()) {
        auto c = s.begin();
        int i = c->second;
        int p = b[(i + 1) % n] + b[(i + n - 1) % n];
        if ((b[i] - a[i]) % p == 0) {
            ret += (b[i] - a[i]) / p;
            b[i] = a[i];
            s.erase(c);
        } else {
            int k = (b[i] - 1) / p;
            ret += k;
            b[i] -= k * p;
            if (k == 0 || b[i] < a[i]) {
                std::cout << -1 << std::endl;
                return 0;
            }
            s.erase(c);
            s.emplace(-b[i], i);
        }
    }

    std::cout << ret << std::endl;

    return 0;
}
