#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll mod = 998244353;
  ll N, S;
  cin >> N >> S;
  vector<ll> dp(S + 1, 0);
  dp.at(0) = 1;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    for (ll j = S; j >= 0; --j) {
      dp.at(j) += dp.at(j);
      dp.at(j) %= mod;
      if (j - a >= 0) {
        dp.at(j) += dp.at(j - a);
        dp.at(j) %= mod;
      }
    }
  }
  cout << dp.at(S) << "\n";
}
