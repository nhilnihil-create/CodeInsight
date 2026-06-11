#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <limits>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <numeric>
#include <tuple>

constexpr long long mod = static_cast<long long>(1e9 + 7);


int main() {
    int V, E;
    std::cin >> V >> E;
    std::vector<std::vector<int>> edges(V);
    std::vector<int> cnts(V, 0);
    while(E--) {
        int s, t;
        std::cin >> s >> t;
        edges[s].push_back(t);
        ++cnts[t];
    }

    std::queue<int> que;
    for(int i = 0; i < V; ++i) {
        if(cnts[i] == 0) que.push(i);
    }

    std::vector<int> ans;
    ans.reserve(V);
    while(!que.empty()) {
        auto v = que.front();
        que.pop();
        ans.push_back(v);
        for(auto u: edges[v]) {
            --cnts[u];
            if(cnts[u] == 0) que.push(u);
        }
    }

    for(auto val: ans)
        std::cout << val << "\n";
    std::cout << std::flush;

    return 0;
}

