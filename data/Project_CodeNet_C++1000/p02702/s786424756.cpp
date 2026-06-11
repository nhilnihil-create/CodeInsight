#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 2019LL;
// const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll dp[200005];

ll fastpow(ll a, ll n, ll mod = MOD) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  string s;
  cin >> s;

  for (ll i = s.size() - 1; i >= 0; i--) {
    auto ch = s.substr(i, 1);

    ll d = stoll(ch);
    ll c = s.size() - i - 1;
    ll v = d * fastpow(10, c);

    dp[i] = (v + dp[i + 1]) % MOD;
  }

  mll m;

  ll sum = 0;
  for (ll i = 0; i <= s.size(); i++) {
    // cout << dp[i] << endl;

    sum += m[dp[i]];
    m[dp[i]]++;
  }

  cout << sum << endl;
}
