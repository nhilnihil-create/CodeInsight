#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
using namespace std;
const ll INF = 1ll << 60;

int main() {
  int h, n, a, b;
  cin >> h >> n;
  vector<ll> dp(h + 1, INF);
  dp[0] = 0;

  rep(i, n) {
    cin >> a >> b;
    rep(j, h) dp[min(j + a, h)] = min(dp[min(j + a, h)], dp[j] + b);
  }

  cout << dp[h] << endl;
}