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
    int n; std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    int ans = 0;
    std::vector<int> v(3);
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 3; j++) v[j] = p[i + j];
        std::sort(v.begin(), v.end());
        if (v[1] == p[i + 1]) ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}