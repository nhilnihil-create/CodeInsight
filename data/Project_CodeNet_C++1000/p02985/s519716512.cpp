#include <iostream>
#include <vector>
#include <queue>
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    // 頂点数と辺数
    int N, K; cin >> N >> K;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = K;
    int c=K-1;
    for(auto x:G[0]){
        dist[x]=c;
        c--;
        que.push(x);
    }

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(),u=K-2; // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = u;
            u--;
            que.push(nv);
        }
    }
    long long ans=1;
    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (int v = 0; v < N; ++v) {
        ans*=dist[v];
        ans%=MOD;
    }
    cout<<ans<<endl;
}