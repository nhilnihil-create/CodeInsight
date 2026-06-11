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

int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> edges(V, std::vector<int>());
    std::vector<int> ins(V, 0);
    std::vector<bool> memo(V, false);

    while(E--){
        int s, t;
        std::cin >> s >> t;
        edges[s].push_back(t);
        ++ins[t];
    }

    std::vector<int> ans;
    ans.reserve(V);

    for(int i = 0; i < V; ++i) {
        if(!memo[i] && ins[i] == 0) {

            std::queue<int> que;
            que.push(i);
            while(!que.empty()) {
                int v = que.front();
                que.pop();
                ans.push_back(v);
                memo[v] = true;

                for(auto val: edges[v]) {
                    --ins[val];
                    if(!memo[val] && ins[val] == 0) {
                        que.push(val);
                    }
                }

            }

        }
    }

    for(int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i];
        if(i < ans.size() - 1) std::cout << " ";
    }

    std::cout << std::flush;

    return 0;
}

