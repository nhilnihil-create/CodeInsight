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
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <numeric>
//#include <tuple>

constexpr long long mod = static_cast<long long>(1e9 + 7);

void dfs(int i, const std::vector<std::vector<int>>& edges, std::vector<bool>& memo, std::vector<int>& ans) {
    memo[i] = true;
    for(auto v: edges[i]) {
        if(!memo[v])dfs(v, edges, memo, ans);
    }
    ans.push_back(i);
}

int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> edges(V, std::vector<int>());
    std::vector<bool> memo(V, false);

    while(E--){
        int s, t;
        std::cin >> s >> t;
        edges[s].push_back(t);
    }

    std::vector<int> ans;
    ans.reserve(V);

    for(int i = 0; i < V; ++i) {
        if(!memo[i]) {

            dfs(i, edges, memo, ans);

        }
    }

    for(auto itr = rbegin(ans); itr != rend(ans); ++itr) {
        std::cout << *itr;
        if(itr + 1 != rend(ans)) std::cout << " ";
    }

    std::cout << std::flush;

    return 0;
}

