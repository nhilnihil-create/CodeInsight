#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); i++)

int m, d, ans;

int main() {
  cin >> m >> d;
  rep(i, 1, m) {
    rep(j, 1, d) {
      int d0 = j % 10, d1 = j / 10;
      if (d0 < 2) continue ;
      if (d1 < 2) continue ;
      if (d0 * d1 != i) continue ;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}