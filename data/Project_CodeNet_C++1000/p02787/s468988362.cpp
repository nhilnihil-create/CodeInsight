#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, n;
  cin >> h >> n;

  vector<int> dp(h + 10, 1e9);
  dp[0] = 0;
  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    for (int j = 1; j < h + 10; j++) {
      if (j <= a) {
        dp[j] = min(dp[j], b);
      } else {
        dp[j] = min(dp[j], dp[j - a] + b);
      }
    }
  }

  cout << dp[h] << endl;
}
