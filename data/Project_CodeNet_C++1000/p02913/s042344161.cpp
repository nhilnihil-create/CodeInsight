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
    std::string s; std::cin >> s;

    auto func = [&](int len) {
        auto comp = [&](int i, int j) {
            return s.substr(i, len) < s.substr(j, len);
        };
        std::set<int, decltype(comp)> st(comp);
        for (int i = n - 2*len; i >= 0; i--) {
            st.insert(i + len);
            auto iter = st.lower_bound(i);
            if (iter != st.end() &&
                    s.substr(*iter, len) == s.substr(i, len)) {
                return true;
            }
        }
        return false;
    };

    int lo = 0, hi = n + 1;
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (func(mid)) lo = mid;
        else hi = mid;
    }
    std::cout << lo << std::endl;
    return 0;
}
