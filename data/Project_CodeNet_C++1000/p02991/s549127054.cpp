#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;

class Solution {
public:

};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; 
    cin >> n;
    int m; 
    cin >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
    }

    int s, t;
    cin >> s >> t;
    --s, --t;

    const int INF = 1 << 29;
    vector<vector<int>> dis(n, vector<int>(3, INF));

    deque<pair<int,int>> que;
    que.emplace_back(s, 0);
    dis[s][0] = 0;

    while (!que.empty()) {
        int u = que.front().first;
        int st = que.front().second;
        que.pop_front();

        for (auto v : graph[u]) {
            int nst = (st + 1) % 3;
            int w = nst == 0 ? 1 : 0;
            if (dis[v][nst] > dis[u][st] + w) {
                dis[v][nst] = dis[u][st] + w;
                if (w == 0) {
                    que.emplace_front(v, nst);
                } else {
                    que.emplace_back(v, nst);
                }
            }
        }
    }

    if (dis[t][0] < INF) {
        cout << dis[t][0] << "\n";
    } else {
        cout << -1 << "\n";
    }


    return 0;
}