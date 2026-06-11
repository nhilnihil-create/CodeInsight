#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------
ll N,K;
vector<vector<int>> G;

ll dfs(int v,int p=-1){
  ll use;
  if(p == -1){
    use = K-1;
  }else{
    use = K-2;
  }
  if(G[v].size() > K){
    return 0;
  }else{
    ll res = 1;
    for(int nv: G[v]){
      if(nv == p) continue;
      res *= use;
      res %= mod;
      use--;
    }
    for(int nv: G[v]){
      if(nv == p) continue;
      res *= dfs(nv,v);
      res %= mod;
    }
    return res;
  }
}

int main(){
  cin >> N >> K;
  G.resize(N);
  for(int i=0; i<N-1; i++){
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  ll ans = K * dfs(0);
  ans %= mod;
  cout << ans << endl;
  return 0;
}
