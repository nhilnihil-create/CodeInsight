#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using field = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  field G(n);
  vector<P> input(n-1);
  rep(i,0,n-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
    input[i] = P(a,b);
  }
  map<P,int> ans;
  vector<bool> seen(n,false);
  queue<int> q;
  vector<int> c(n,0);
  q.push(0);
  int md = 0;
  while(!q.empty()) {
    int v = q.front(); q.pop();
    seen[v] = true;
    int cnt = 1;
    for (auto nv : G[v]) {
      if (seen[nv]) continue;
      if (cnt == c[v]) cnt++;
      c[nv] = ans[P(v,nv)] = ans[P(nv,v)] = cnt++;
      md = max(md,cnt-1);
      q.push(nv);
    }
  }
  cout << md << endl;
  for (auto p : input) {
    cout << ans[p] << endl;
  }
  return 0;
}
