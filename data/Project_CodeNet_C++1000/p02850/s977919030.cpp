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
    std::vector<std::vector<int>> edg(n), id(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; std::cin >> a >> b;
        a--; b--;
        edg[a].push_back(b);
        edg[b].push_back(a);
        id[a].push_back(i);
        id[b].push_back(i);
    }
    std::vector<int> ans(n - 1);
    auto dfs = [&](auto &self, int pos = 0,
        int prev = -1, int prevc = -1) -> void {
        
        int cnt = 1;
        for (int i = 0; i < edg[pos].size(); i++) {
            int c = edg[pos][i];
            if (c == prev) continue;
            if (cnt == prevc) cnt++;
            ans[id[pos][i]] = cnt++;
            self(self, c, pos, ans[id[pos][i]]);
        }
    };
    dfs(dfs);
    std::cout << *std::max_element(ans.begin(), ans.end()) << std::endl;
    for (int i = 0; i < n - 1; i++) std::cout << ans[i] << "\n";
    return 0;
}
