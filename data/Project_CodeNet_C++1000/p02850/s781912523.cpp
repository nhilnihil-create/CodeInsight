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
using Edge = pii;
using Graph = vector<vector<Edge>>;
int n;
Graph G;

void dfs(int n, int par, int pc, vector<int>& res){
  int color = 1;
  if(color == pc) color++;
  for(auto e: G[n]){
    if(res[e.second] != -1) continue;
    res[e.second] = color;
    dfs(e.first, n, color, res);
    color++;
    if(color == pc) color++;
  }
}

int main() {
  cin >> n;
  G.assign(n, vector<Edge>());
  rep(i, n-1){
    int a, b; cin >> a >> b; a--; b--;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }

  int mx = 0;
  rep(i, n) chmax(mx, (int)G[i].size());

  vector<int> res(n, -1);
  dfs(0, -1, -1, res);

  cout << mx << ln;
  rep(i, n-1) cout << res[i] << ln;
}
