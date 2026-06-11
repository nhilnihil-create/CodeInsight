#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, x, y; cin >> n >> x >> y;

    // dist[i][j] = iからjへの最短距離
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // 頂点iから全頂点への最短距離を求める
    // N頂点に対しO(N)の幅優先探索を行うためO(N^2)
    for (int i = 0; i < n; ++i) {
        queue<int> que;
        que.push(i);
        dist[i][i] = 0;

        // 幅優先探索 O(N)
        while (!que.empty()) {
            int cur = que.front(); que.pop();

            vector<int> vs;
            vs.push_back(cur - 1);
            vs.push_back(cur + 1);
            if (cur == y - 1) vs.push_back(x - 1);
            if (cur == x - 1) vs.push_back(y - 1);

            for (auto v : vs) {
                if (v < 0 || n <= v) continue;
                if (dist[i][cur] + 1 < dist[i][v]) {
                    dist[i][v] = dist[i][cur] + 1;
                    que.push(v);
                }
            }
        }
    }

    // dist[k] = 最短距離がkな頂点の組み合わせの数
    vector<int> dists(n - 1, 0);

    // 「AからBへの最短距離」 から 「最短距離がKな頂点の組み合わせの数」 へ変換
    // nC2 = n * (n - 1) / 2 のループ O(N^2)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ++dists[dist[i][j] - 1];
        }
    }

    for (auto ans : dists) {
        cout << ans << endl;
    }
}

