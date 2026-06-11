#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long;
using namespace std;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  int cs[12] = {};
  int as[12][12] = {{}};
  rep(i, n) {
    cin >> cs[i];
    rep(j, m) { cin >> as[i][j]; }
  }
  int mmmoney = 100000000;
  for (int bit = 1; bit < (1 << n); bit++) {
    int money = 0;
    int totals[m];
    rep(i, m) { totals[i] = 0; }
    rep(i, n) {
      if (bit & (1 << i)) {
        rep(j, m) { totals[j] += as[i][j]; }
        money += cs[i];
      }
    }
    bool c = true;
    rep(i, m) {
      if (totals[i] < x) {
        c = false;
      }
    }
    if (c) {
      mmmoney = min(mmmoney, money);
    }
  }
  if (mmmoney == 100000000) {
    mmmoney = -1;
  }
  cout << mmmoney << endl;
  return 0;
}