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
    std::vector<int> cnt(n + 2);
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        cnt[a]++;
    }
    std::sort(cnt.rbegin(), cnt.rend());
    int pos = 0, res = n;
    int w = 1e9;
    for (int i = 1; i <= n; i++) {
        w = std::min(w, n / i);
        while (w > 0) {
            while (cnt[pos] > w) {
                res -= cnt[pos++];
            }
            if (pos + res / w >= i) {
                std::cout << w << std::endl;
                break;
            }
            w--;
        }
        if (w == 0) {
            std::cout << 0 << std::endl;
        }
    }
    return 0;
}