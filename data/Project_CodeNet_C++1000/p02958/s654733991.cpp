#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  bool pos = false;
  rep(i, n) rep(j, n) {
    vector<int> q(n);
    rep(k, n) q[k] = p[k];
    swap(q[i], q[j]);
    bool now = true;
    rep(k, n-1) if (q[k] > q[k+1]) now = false;
    if (now) pos = true;
  }
  if (pos) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}