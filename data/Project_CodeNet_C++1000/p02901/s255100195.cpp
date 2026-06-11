#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
  ll n, m, c;
  cin >> n >> m;
  ll a[m], b[m], mask[m] = {0};
  rep(i, m) {
    cin >> a[i] >> b[i];
    rep(j, b[i]) {
      cin >> c, c--;
      mask[i] += pow(2, c);
    }
  }

  ll dp[1 << n];
  rep(i, 1 << n) dp[i] = INF;
  dp[0] = 0;

  rep(i, 1 << n) rep(j, m) dp[i | mask[j]] = min(dp[i | mask[j]], dp[i] + a[j]);
  ll ans = dp[(1 << n) - 1];
  cout << (ans != INF ? ans : -1) << endl;
  return 0;
}