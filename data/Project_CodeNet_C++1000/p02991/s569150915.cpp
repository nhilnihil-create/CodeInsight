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
    std::vector<std::vector<int>> edg(n);
    for (int i = 0; i < m; i++) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        edg[u].push_back(v);
    }
    int s, t; std::cin >> s >> t;
    s--; t--;
    std::vector<std::vector<int>> dist(n, std::vector<int>(3, 1e9));
    std::priority_queue<std::pair<int, std::pair<int, int>>> que;
    que.push({ 0, {s, 0} });
    dist[s][0] = 0;
    while (!que.empty()) {
        int d = -que.top().first;
        int pos = que.top().second.first;
        int st = que.top().second.second;
        que.pop();

        int nxtst = (st + 1) % 3;
        int nxtd = d + (st == 2);
        for (int e : edg[pos]) {
            if (dist[e][nxtst] <= nxtd) continue;
            dist[e][nxtst] = nxtd;
            que.push({ -nxtd, { e, nxtst } });
        }
    }
    std::cout << (dist[t][0] != 1e9 ? dist[t][0] : -1) << std::endl;
    return 0;
}