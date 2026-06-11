#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<i64, i64>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        v.emplace_back(x, y);
    }

    std::sort(v.begin(), v.end(), [](const auto &lhs, const auto &rhs) {
        return std::atan2(lhs.first, lhs.second) < std::atan2(rhs.first, rhs.second);
    });
    for (int i = 0; i < n; i++) v.push_back(v[i]);

    i64 ret = 0;
    for (int i = 0; i < n; i++) {
        i64 x = 0, y = 0;
        for (int j = 0; j < n; j++) {
            x += v[i + j].first;
            y += v[i + j].second;
            ret = std::max(ret, x * x + y * y);
        }
    }

    std::cout << std::fixed << std::setprecision(12) << std::sqrt(ret) << std::endl;

    return 0;
}
