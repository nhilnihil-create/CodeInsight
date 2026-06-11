#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

const int INF = 1000000007;
int main() {
  int n, m;
  cin >> n >> m;
  vector<P> keys;
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    int s = 0;
    rep(j, 0, b) {
      int c;
      cin >> c;
      c--;
      s |= 1 << c;
    }
    keys.emplace_back(s, a);
  }

  vector<int> dp(1 << n, INF);
  dp[0] = 0;
  rep(s, 0, 1 << n) {
    rep(i, 0, m) {
      int t = s | keys[i].first;
      int cost = dp[s] + keys[i].second;
      chmin(dp[t], cost);
    }
  }

  int ans = dp[dp.size()-1];
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
}
