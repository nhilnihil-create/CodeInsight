#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

const int INF = 1e9;

signed main() {
  int n,k,s;
  cin >> n >> k >> s;

  vector<int> ans(n, INF);
  if(s == INF) {
    rep(i,n) ans[i] = INF - 1;
  }
  rep(i, k) ans[i] = s;

  for (auto it : ans) cout << it << " ";
  cout << '\n';

}

