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
    std::vector<std::pair<int, int>> ans;
    for (int i = 1; i < n; i++) {
        ans.emplace_back(1, i + 1);
    }
    int cnt = (n - 1)*(n - 2)/2;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cnt <= k) break;
            ans.emplace_back(i + 1, j + 1);
            cnt--;
        }
    }
    if (cnt != k) {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << ans.size() << std::endl;
    for (auto p : ans) std::cout << p.first << " " << p.second << std::endl;
    return 0;
}
