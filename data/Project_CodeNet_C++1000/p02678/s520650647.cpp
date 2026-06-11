#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;
using Graph = vector<vector<int>>;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N+1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // BFS のためのデータ構造
    vector<int> dist(N+1, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 1 を初期ノードとする)
    dist[1] = 0;
    que.push(1); // 1 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

int ans[N+5] = {};

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (int v = 2; v <= N; ++v) {
        //cout << v << ": " << dist[v] << endl;
        for (int nv : G[v]) {
            //cout << "v:" << v << " nv:" << nv << endl;
            if(dist[nv]==dist[v]-1) {
                //cout << nv << endl;
                ans[v] = nv;
                break;
            }
        }
    }

    for(int i=2; i<=N; i++) {
        if(ans[i]==0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for(int i=2; i<=N; i++) {
        cout << ans[i] << endl;
    }
}