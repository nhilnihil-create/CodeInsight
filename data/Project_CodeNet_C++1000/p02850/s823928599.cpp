#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using Graph = vector<vector<pii>>;
int n;
Graph G;

int main() {
  cin >> n;
  G.assign(n, vector<pii>());
  rep(i, n - 1){
    int a, b; cin >> a >> b; a--; b--;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }
  int mx = 0;
  rep(i, n) chmax(mx, (int)G[i].size());
  vector<int> res(n-1, -1);

  vector<int> dist(n, -1);
  queue<pii> que;
  que.push({0, -1});
  dist[0] = 0;
  while(!que.empty()){
    auto p = que.front(); que.pop();
    int v = p.first, c = p.second;
    int color = 1;
    if(color == c) ++color;
    for(auto e : G[v]){
      if(dist[e.first] == -1){
        dist[e.first] = dist[v] + 1;
        que.push({e.first, color});
        res[e.second] = color;
        color++;
        if(color == c) color++;
      }
    }
  }
  cout << mx << ln;
  for(auto v: res) cout << v << ln;
  
}
    
