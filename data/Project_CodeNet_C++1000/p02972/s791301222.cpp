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
    bool cur[200005] = {}, targ[200005] = {};
    std::vector<int> ans;
    for (int i = 1; i <= n; i++) std::cin >> targ[i];
    for (int i = n; i >= 1; i--) {
        if (cur[i] ^ targ[i]) {
            ans.push_back(i);
            for (int j = 1; j*j <= i; j++) {
                if (i%j != 0) continue;
                cur[j] ^= true;
                if (j*j != i) cur[i / j] ^= true;
            }
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) flag &= targ[i] == cur[i];
    if (!flag) {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << ans.size() << std::endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }
    return 0;
}
