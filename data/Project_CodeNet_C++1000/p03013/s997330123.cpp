#include <iostream>

using namespace std;
using ll = long long;

ll mod = 1000000007;

ll hoge(ll x) {
  static ll data[100001] = {};
  if (data[x])
    return data[x];
  return data[x] = (x <= 1) ? 1 : (hoge(x-1) + hoge(x-2)) % mod;
}

int main() {
  ll n, m;
  cin >> n >> m;

  for (ll i = 0; i < 1e5+1; ++i)
    hoge(i);

  ll cur = 0;
  ll ans = 1;
  for (ll i = 0; i < m; ++i) {
    ll a;
    cin >> a;
    if (cur == a)
      ans = 0;
    ans = ans * hoge(a - 1 - cur) % mod;
    cur = a + 1;
  }
  cout << ans * hoge(n - cur) % mod << endl;
}