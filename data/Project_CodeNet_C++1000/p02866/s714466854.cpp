#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll mod = 998244353;

int main() {
  ll n;
  cin >> n;
  vector<ll> vec(1e5, 0);
  ll initial;
  for (ll i = 0; i < n; ++i) {
    ll tmp;
    cin >> tmp;
    ++vec[tmp];
    if (i == 0)
      initial = tmp;
  }

  ll ans = int((vec[0] == 1) && (initial==0));
  for (ll i = 1; i < 1e5; ++i) {
    for (ll j = 0; j < vec[i]; ++j)
      ans = (ans * vec[i-1]) % mod;
  }

  cout << ans << endl;
}
