#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N),g(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
    }
    int s,t;cin>>s>>t;
    s--;t--;
    // BFS のためのデータ構造
    vector<int> dist(N, -1),seen(N,-1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[s] = 0;
    que.push(s); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            for(int nnv : G[nv]){
                for(int nnnv : G[nnv]){
                    if(dist[nnnv]!=-1)continue;
                    dist[nnnv]=dist[v]+1;
                    if(nnnv==t){
                        cout<<dist[nnnv]<<endl;
                        return 0;
                    }
                    que.push(nnnv);
                }
            }
        }
    }

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    cout<<dist[t]<<endl;
}
