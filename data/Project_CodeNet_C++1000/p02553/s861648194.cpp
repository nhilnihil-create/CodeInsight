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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(max(a * c, a * d), max(b * c, b * d)) << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}