#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;
const ll MOD = 1e9 + 7;

// log N
inline ll fast(ll n, ll k) {
  if (k == 1) {
    return n;
  } else if (k == 0) {
    return 1;
  }

  if (k % 2 == 0) {
    ll ret = fast(n, k / 2) % MOD;
    return ret * ret % MOD;
  } else {
    ll ret = fast(n, k / 2) % MOD;
    ll tmp = ret * ret % MOD;
    return tmp * n % MOD;
  }
}

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> GCD(K + 1);

  for (ll i = 1; i <= K; i++) {
    GCD[i] = fast(K / i, N) % MOD;
  }

  ll ans = 0;
  vector<ll> sum(K + 1);

  for (ll i = K; i > 0; i--) {
    ll n = GCD[i];
    for (ll j = 2; j <= (K / i); j++) {
      n -= sum[i * j];
      if (n < 0) {
        n = (n + MOD) % MOD;
      }
    }
    ans += (n * i);
    if (ans < 0) {
      ans = (ans + MOD);
    }
    ans %= MOD;
    sum[i] = n;
  }
  cout << ans << endl;
}