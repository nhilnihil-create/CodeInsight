#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

vector<bool> c;
vector<int> s;
vector<vector<int>> v;

void dfs(int n) {
  for(auto nn : v[n]) {
    if(c[nn]) {
      c[nn] = false;
      s[nn] += s[n];
      dfs(nn);
    }
  }
}
int main() {
  int N, Q, a, b, p, x;cin >> N >> Q;
  c.assign(N, true);
  s.assign(N, 0);
  v.resize(N);
  rep(i, N-1) {
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  rep(i, Q) {
    cin >> p >> x;
    s[p-1] += x;
  }
  c[0] = false;
  dfs(0);
  for(auto y : s) cout << y << " ";
}