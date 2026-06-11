#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

using Graph = vector<vector<int>>;

Graph g;
vector<int> p;
vector<int> x;
vector<bool> seen;

void dfs (int a, int cur) {
  seen[a] = true;
  x[a] = cur + p[a];
  for(auto b : g[a]) {
    if(seen[b]) continue;
    dfs(b, x[a]);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  g.resize(n+1);
  p.resize(n+1);
  x.resize(n+1);
  seen.resize(n+1);

  rep(i, n-1) {
    int ai, bi;
    cin >> ai >> bi;
    g[ai].push_back(bi);
    g[bi].push_back(ai);
  }
  rep(i, q) {
    int pi, xi;
    cin >> pi >> xi;
    p[pi] += xi;
  }

  dfs(1, 0);

  for(int i=1;i<=n;i++) {
    if(i != n) {
      cout << x[i] << " ";
      continue;
    }
    cout << x[n] << endl;
  }
  return 0;
}
