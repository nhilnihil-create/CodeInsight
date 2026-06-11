#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i, n) for(int (i)=0; (i)< (n); ++i)
#define REPR(i, n) for(int (i)=(n); (i)>=0; --i)
#define FOR(i, n, m) for(int (i)=(n); (i)<(m); ++i)
constexpr ll INF = 1LL << 60;
constexpr int mod = 1e9+7;

int N, K;
vector<vector<int>> g;
vector<bool> homon;
ll ans = 1;
void dfs(int v){
  homon[v] = true;
  int cnt = 1;
  if(v != 0) cnt++;
  for(auto nv : g[v]){
    if(homon[nv]) continue;
    ans *= K-cnt;
    ans %= mod;
    dfs(nv);
    cnt++;
  }
}
int main(){
  cin >> N >> K;
  g.resize(N);
  REP(i, N-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  homon.resize(N);
  ans *= K;
  dfs(0);
  cout << ans << endl;
  return 0;
}
