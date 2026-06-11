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
    int n, m; std::cin >> n >> m;
    std::string s; std::cin >> s;
    std::set<int> st;
    for (int i = 0; i <= n; i++)
        if (s[i] == '0') st.insert(i);
    int pos = n;
    std::vector<int> ans;
    int cnt = 0;
    while (pos > 0) {
        auto iter = st.lower_bound(pos - m);
        ans.push_back(pos - *iter);
        pos = *iter;
        cnt++;
        if (cnt > n) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::reverse(ans.begin(), ans.end());
    for (int i : ans) std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}

