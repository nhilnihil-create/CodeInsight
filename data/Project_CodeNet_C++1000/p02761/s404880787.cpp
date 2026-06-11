#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(m), c(m);
  rep(i, m) {
    cin >> s[i] >> c[i];
    --s[i];
  }

  vector<int> d(n, -1);
  rep(i, m) {
    if (d[s[i]] != -1 && d[s[i]] != c[i]) {
      cout << -1 << endl;
      return 0;
    }
    d[s[i]] = c[i];
  }

  if (n == 1 && d[0] <= 0) {
    cout << 0 << endl;
    return 0;
  }

  if (d[0] == 0) {
    cout << -1 << endl;
    return 0;
  }

  rep(i, n) {
    if (d[i] != -1) cout << d[i];
    else if (i == 0) cout << 1;
    else cout << 0;
  }
  cout << endl;
  
  return 0;
}