#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

void solve() {
  ll n;
  cin >> n;
  vector<string> v;
  string x;
  for (ll i = 0; i < n; ++i) {
    cin >> x;
    sort(x.begin(), x.end());
    v.emplace_back(x);
  }
  sort(v.begin(), v.end());
  vector<ll> aux;
  ll len = 1;
  for (ll i = 0; i < n - 1; ++i) {
    if (v[i] == v[i + 1]) {
      ++len;
    } else {
      aux.emplace_back(len);
      len = 1;
    }
  }
  aux.emplace_back(len);
  ll ans = 0;
  for (ll x : aux) {
    ans += (1ll * (x * x - x)) >> 1;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}