#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  ll sum = 0;
  rep(i, n) {
    sum += a.at(i);
  }
  vector<ll> res(n);
  // 計算
  ll minus = 0;
  rep(i, n) {
    if (i % 2 == 1) {
      minus += a.at(i);
    }
  }
  res.at(0) = sum - 2 * (minus);
  rep(i, n - 1) {
    res.at(i + 1) = 2 * a.at(i) - res.at(i);
  }
  // 出力
  rep(i, n) {
    if (i != 0) {
      cout << " ";
    }
    cout << res.at(i);
  }
  return 0;
}
