#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


vector<int> ve[200001];
vector<int> ans;

void dfs(int v, int p = -1) {
  for(int u : ve[v]) {
    if(u == p) continue;
    ans[u] += ans[v];
    dfs(u,v);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    ve[a].push_back(b);
    ve[b].push_back(a);
  }
  ans.resize(n);
  rep(i,q) {
    int p, x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }
  dfs(0);
  for(int i=0; i<n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}