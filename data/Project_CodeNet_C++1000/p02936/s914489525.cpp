#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using graph = map<int, vector<int>>;
 
int dfs(graph &G, vector<bool> &seen, int v, int cnt, vector<int> &ans, vector<int> &px) {
  seen[v] = true;
  cnt += px[v];
  ans[v] = cnt;
  for (auto nv : G[v]) {
    if (seen[nv]) continue;
    dfs(G,seen,nv,cnt,ans,px);
  }
  cnt -= px[v];
  return 0;
}
 
int main() {
  int n,q;
  cin >> n >> q;
  graph G;
  rep(i,0,n-1) {
    int a,b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> px(n+1,0);
  rep(i,0,q) {
    int p,x;
    cin >> p >> x;
    px[p] += x;
  }
  vector<bool> seen(n+1,false);
  vector<int> ans(n+1,0);
  
  dfs(G,seen,1,0,ans,px);
 
  rep(i,1,n) cout << ans[i] << " ";
  cout << ans[n] << endl;
 
  return 0;
}