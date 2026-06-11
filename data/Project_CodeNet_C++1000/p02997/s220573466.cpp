#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


int main() {
    int n, k; std::cin >> n >> k;
    if (k > (n - 1)*(n - 2) / 2) {
        std::cout << -1 << std::endl;
        return 0;
    }
    bool edg[102][102];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            edg[i][j] = false;
    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        ans.emplace_back(i + 1, n);
        edg[i][n - 1] = true;
    }
    for (int t = 0; t < (n - 1)*(n - 2) / 2 - k; t++) {
        [&]() {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (edg[i][j]) continue;
                    edg[i][j] = true;
                    ans.emplace_back(i + 1, j + 1);
                    return;
                }
            }
        }();
    }
    std::cout << ans.size() << std::endl;
    for (const auto &e : ans)
        std::cout << e.first << " " << e.second << std::endl;
    return 0;
}
