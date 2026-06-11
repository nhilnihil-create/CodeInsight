#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> as(n + 1), bs(n);
  rep(i, n + 1) cin >> as[i];
  rep(i, n) cin >> bs[i];
  ll ans = 0;
  rep(i, n) {
    if (as[i] <= bs[i]) {
      ans += as[i];
      ll diff = bs[i] - as[i] <= as[i + 1] ? bs[i] - as[i] : as[i + 1];
      ans += diff;
      as[i + 1] -= diff;
    } else {
      ans += bs[i];
    }
  }
  cout << ans << endl;
  return 0;
}
