#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORe(i, k, n) for(int i = (k); i <= (n); i++)
#define FORr(i, k, n) for(int i = (k); i > (n); i--)
#define FORre(i, k, n) for(int i = (k); i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

const int INF = 1001001001;
const int mod = 1000000007;

int k;
ll ans;
vector<vector<int>> to(100000);

void dfs(int v, int p = -1){
  for(int u : to[v]){
    if(u == p) continue;
    dfs(u, v);
  }
  int nk = (p==-1) ? k : k-2;
  int nc = (p==-1) ? to[v].size()+1 : to[v].size()-1;
  ll kpc = 1;
  REP(i, nc) kpc = kpc * (nk-i) % mod;
  ans = (ans*kpc) % mod;
}

int main(void){
  int n;
  cin >> n >> k;
  
  REP(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    to[a].emplace_back(b);
    to[b].emplace_back(a);
  }

  ans = 1;
  dfs(0);
  cout << ans << endl;

  return 0;
}