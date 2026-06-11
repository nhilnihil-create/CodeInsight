#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int N, M;  //N頂点M辺
vector<int> visited;
vector<vector<int>> G;



int main() {
    cin >> N;
    M=N-1;
    pair<int,int>p[M];
    G = vector<vector<int>>(N); // サイズを確保する
    visited = vector<int>(N, 0); // 全頂点を「未訪問」に初期化
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        // 頂点番号を 0-indexed とする
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        p[i]=make_pair(a,b);
    }
    
    int qq[N];
    qq[0]=0;
    map<pair<int,int>,int> ans;

    queue<int> que;
    int ft=0; //大体 0 なのでft=0としてカットしても良い

    que.push(ft); // ft を橙色頂点にする
    visited[ft]=1; // 初期条件 (頂点 ft を初期ノードとする)

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        int d=1;

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (visited[nv] != 0) continue; // すでに発見済みの頂点は探索しない
            if(qq[v]==d){d++;qq[nv]=d;ans[make_pair(v,nv)]=d;}else{qq[nv]=d;ans[make_pair(v,nv)]=d;}
            d++;

            // 新たな白色頂点 nv についてキューに追加する（距離情報を更新する場合はvisited[v]+1）
            visited[nv] = 1;
            que.push(nv);
        }
    }

  int q=0;
  rep(i,N)chmax(q,qq[i]);
  cout << q << endl;
  for(int i=0;i<M;i++){
    cout << ans[p[i]] << endl;
  }

    
}