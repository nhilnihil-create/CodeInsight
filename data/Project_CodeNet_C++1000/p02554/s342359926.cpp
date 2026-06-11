#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

ll bow(ll x, ll y) {
  ll res = 1;
  for (ll i = 1; i <= y; ++i) {
    res = res * x % mod;
  }
  return res;
}

void solve() {
  ll n;
  cin >> n;
  ll ans = bow(10, n) - bow(9, n) - bow(9, n) + bow(8, n);
  ans %= mod;
  ans = (ans + mod) % mod;
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
