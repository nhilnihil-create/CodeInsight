#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &e : a) std::cin >> e;

    for (int i = 0; i < k; i++) {
        std::vector<int> next(n + 1);
        for (int j = 0; j < n; j++) {
            const int l = std::max(0, j - a[j]),
                r = std::min(n, j + a[j] + 1);
            next[l]++;
            next[r]--;
        }

        for (int j = 1; j <= n; j++) next[j] += next[j - 1];
        next.pop_back();

        std::swap(a, next);
        if (std::all_of(a.begin(), a.end(), [n](const int e) { return e == n; })) {
            break;
        }
    }

    for (const auto &e : a) std::cout << e << ' ';
    std::cout << std::endl;

    return 0;
}
