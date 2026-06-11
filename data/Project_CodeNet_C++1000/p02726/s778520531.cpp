#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int main() {
 ll n,x,y;
  cin>>n>>x>>y;
  x--;y--;
  vector<vll> g(n);
  rep(i,n-1){
   g[i].push_back(i+1);
   g[i+1].push_back(i);
  }
  g[x].push_back(y);
  g[y].push_back(x);
  ll cnt[2200][2200]; //始まり,距離
  rep(i,n){
   vector<ll> dist(n, -1); // 全頂点を「未訪問」に初期化
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[i] = 0;
    que.push(i); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (ll nv : g[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
           cnt[i][dist[nv]]++;
            que.push(nv);
        }
    }
    
    
  }//for
    for(int i=1;i<n;i++){
      ll ans=0;
      for(int j=0;j<n;j++){
         ans+=cnt[j][i];
        //cout<<cnt[j][i]<<" "<<j<<i<<endl;
      }
      cout<<ans/2<<endl;
    }
}