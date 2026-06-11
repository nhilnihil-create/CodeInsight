#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

ll powMod(ll x, ll k) {
  if (k == 0) return 1;
  if (k % 2 == 0)
    return powMod(x * x % MOD, k / 2);
  else
    return x * powMod(x, k - 1) % MOD;
}

ll p[100010];

int main() {
  ll N, K;
  cin >> N >> K;

  ll ret = 0;
  for (ll i = K; i >= 1; i--) {
    ll pm = powMod(K / i, N);
    for (ll j = 2; j * i <= K; j++) {
      pm = (pm + MOD - p[i * j]) % MOD;
    }
    ret = (ret + MOD + i * pm % MOD) % MOD;
    p[i] = pm;
  }
  cout << ret << endl;
}
