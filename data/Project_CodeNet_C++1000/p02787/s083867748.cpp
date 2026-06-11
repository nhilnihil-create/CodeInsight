#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const int INF = 1e8;

int main() {
  int h, n;
  cin >> h >> n;
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  V<int> dp(h + 10, INF);
  rep(i, h + 1) {
    rep(j, n) {
      if (i + 1 > a[j]) {
        dp[i + 1] = min(dp[i + 1], dp[i + 1 - a[j]] + b[j]);
      } else {
        dp[i + 1] = min(dp[i + 1], b[j]);
      }
    }
  }
  cout << dp[h] << endl;
}
