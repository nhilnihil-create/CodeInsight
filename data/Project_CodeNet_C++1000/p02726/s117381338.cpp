#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main() {

	int n, x, y; cin >> n >> x >> y;
    x--;
    y--;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(n);
    for (int i = 0; i <= n - 2; ++i) {
        int a, b;
        a = i;
        b = i + 1;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    G[x].push_back(y);
    G[y].push_back(x);

    vector<int> ans(n, 0);
    vector<vector<int>> dist_c(n, vector<int>(n, 0));

    for (int start = 0; start < n; start++) {

        // BFS のためのデータ構造
        vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
        queue<int> que;

        // 初期条件 (頂点 0 を初期ノードとする)
        dist[start] = 0;
        que.push(start); // 0 を橙色頂点にする

        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            int v = que.front(); // キューから先頭頂点を取り出す
            que.pop();

            // v から辿れる頂点をすべて調べる
            for (int new_v : G[v]) {
                if (dist[new_v] != -1) continue; // すでに発見済みの頂点は探索しない

                // 新たな白色頂点 new_v について距離情報を更新してキューに追加する
                dist[new_v] = dist[v] + 1;
                que.push(new_v);

                dist_c[start][new_v] = dist[new_v];
            }
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans[dist_c[i][j]]++;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << ans[i] << endl;
    }
	return 0;
}