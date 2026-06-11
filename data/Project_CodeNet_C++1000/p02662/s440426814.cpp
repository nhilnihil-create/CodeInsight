#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;

#define rep(i, n) for (ll i = 0; i < (n); i++)

#define MOD 998244353

ll dp[3002] = {};

int main() {
  ll n, s;
  cin >> n >> s;
  vector<ll> a(n);

  rep(i, n) {
    cin >> a[i];
  }

  dp[0] = 1;
  rep(i, n) {
    for (ll j = s; j >= 0; j--) {
      if (j + a[i] <= s) {
        dp[j + a[i]] += dp[j];
        dp[j + a[i]] %= MOD;
      }
      dp[j] *= 2;
      dp[j] %= MOD;
    }
  }

  cout << dp[s] << endl;

  return 0;
}