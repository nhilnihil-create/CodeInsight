#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int N,q;  //N頂点M辺
vector<int> visited;
vector<vector<int>> G;


int main() {
    cin >> N >>q;
    ll ans[N]={};
    G = vector<vector<int>>(N); // サイズを確保する
    visited = vector<int>(N, 0); // 全頂点を「未訪問」に初期化
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        // 頂点番号を 0-indexed とする
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,q){
      ll a,b;
      cin >> a >> b;
      a--;
      ans[a]+=b;
    }
    
    queue<int> que;
    int ft=0;

    que.push(ft); // ft を橙色頂点にする
    visited[ft]=1; // 初期条件 (頂点 ft を初期ノードとする)

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (visited[nv] != 0) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv についてキューに追加する（距離情報を更新する場合はvisited[v]+1）
            visited[nv] = 1;
            ans[nv]+=ans[v];
            que.push(nv);
        }
    }
    rep(i,N)cout << ans[i] <<" ";
    cout << endl;

}