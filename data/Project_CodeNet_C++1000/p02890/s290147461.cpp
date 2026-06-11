#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        ++cnt[--a];
    }
    std::sort(cnt.begin(), cnt.end());
    cnt.push_back(n + 1);  // 番兵

    std::vector<int> get(n + 1, -1);
    // 各整数を高々m枚選べるとき，最大何枚選べるか
    int m = 0, sum = 0;
    for (int i = 0; i <= n; ++i) {
        while (m <= n && m < cnt[i]) {
            get[m] = sum + (n - i) * m;
            ++m;
        }
        sum += cnt[i];
    }

    for (int k = 1; k <= n; ++k) {
        lint ok = 0, ng = n + 1;
        while (ng - ok > 1) {
            lint mid = (ok + ng) / 2;
            // mid * k枚選ばなくてはならない
            (mid * k <= get[mid] ? ok : ng) = mid;
        }
        std::cout << ok << std::endl;
    }
    return 0;
}
