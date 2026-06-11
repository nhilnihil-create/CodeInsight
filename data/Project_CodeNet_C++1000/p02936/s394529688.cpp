#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main() {

	int n, q; cin >> n >> q;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> weight(n, 0);
    for (int i = 0; i < q; i++) {
        int p, x; cin >> p >> x;
        p--;
        weight[p] += x;
    }

    // BFS のためのデータ構造
    vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする

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
            weight[new_v] += weight[v];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << weight[i] << " ";
    }
    cout << endl;
	return 0;
}