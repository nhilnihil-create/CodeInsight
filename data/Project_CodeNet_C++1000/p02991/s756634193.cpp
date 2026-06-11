#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, n) for (int i = 1; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(3 * N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[3 * u].push_back(3 * v + 1);
        G[3 * u + 1].push_back(3 * v + 2);
        G[3 * u + 2].push_back(3 * v);
    }
    int S, T;
    cin >> S >> T;
    --S;
    --T;
    
    vector<int> dist(3 * N, -1);
    queue<int> q;
    dist[3 * S] = 0;
    q.push(3 * S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    if (dist[3 * T] == -1) cout << -1 << "\n";
    else cout << dist[3 * T] / 3 << "\n";
    return 0;
}
