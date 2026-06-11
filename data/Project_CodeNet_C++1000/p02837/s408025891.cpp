#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int A = 15;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> x(n, vector<int>(A)), y(n, vector<int>(A));
  rep(i, n) {
    cin >> a[i];
    rep(j, a[i]) {
      cin >> x[i][j] >> y[i][j];
      --x[i][j];
    }
  }

  int ans = 0;
  rep(bit, 1<<n) {
    int now = 0;
    bool ok = true;
    rep(i, n) {
      if (!(bit & 1<<i)) continue;
      ++now;
      rep(j, a[i]) {
        if (y[i][j] == 1 && !(bit & 1<<x[i][j])) ok = false;
        if (y[i][j] == 0 && bit & 1<<x[i][j]) ok = false;
      }
    }
    if (ok) ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}