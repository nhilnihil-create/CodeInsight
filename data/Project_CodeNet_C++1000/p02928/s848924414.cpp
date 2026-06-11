#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll mod = 1000000007;

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> as(n);
  for (auto &v : as)
    cin >> v;

  ll ans = 0;
  for (ll i = 0; i < n; ++i)
    for (ll j = i + 1; j < n; ++j) {
      ans = (ans + (as[i] > as[j])) % mod;
    }
  ans = ans * k % mod;

  ll m = 0;
  for (ll i = 0; i < n; ++i)
    for (ll j = 0; j < n; ++j)
      m = (m + (as[i] > as[j])) % mod;

  ll g = k * (k - 1) / 2 % mod;
  ans = (ans + m * g % mod) % mod;

  cout << ans << endl;

}
