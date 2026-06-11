#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll mod = 998244353;
  ll N, S;
  cin >> N >> S;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  vector<ll> dp(S + 1, 0);
  dp.at(0) = 1;
  for (ll i = 0; i < N; ++i) {
    vector<ll> temp = dp;
    ll a = A.at(i);
    for (ll j = 0; j <= S; ++j) {
      temp.at(j) += dp.at(j);
      temp.at(j) %= mod;
      if (j + a <= S) {
        temp.at(j + a) += dp.at(j);
        temp.at(j + a) %= mod;
      }
    }
    dp = temp;
  }
  // for (ll i = 0; i <= S; ++i) {
  //   cout << dp.at(i) << "\n";
  // }
  cout << dp.at(S) << "\n";
}
