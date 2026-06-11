#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;

ll pow_mod(ll n, ll k) {
  if (k == 0) {
    return 1;
  }
  ll tmp = pow_mod(n, k / 2);
  ll res = tmp * tmp % MOD;
  if (k % 2 != 0) {
    res = n * res % MOD;
  }
  return res;
}

void init(vector<ll>& fact, vector<ll>& finv) {
  ll n = fact.size();
  fact[0] = 1;
  for (ll i = 1; i < n; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  finv[n - 1] = pow_mod(fact[n - 1], MOD - 2);
  for (ll i = n - 2; i > 0; --i) {
    finv[i] = finv[i + 1] * (i + 1) % MOD;
  }
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<ll> fact(n + k + 1);
  vector<ll> finv(n + k + 1);
  init(fact, finv);

  auto choose_mod = [&](ll a, ll b) {
    return a == b || b == 0 ? 1 : (fact[a] * finv[b] % MOD) * finv[a - b] % MOD;
  };

  int m = n - k;
  for (int i = 1; i <= k; ++i) {
    if (m > 1) {
      ll b = choose_mod(k - 1, i - 1);
      ll r = m + 1 >= i ? choose_mod(m + 1, i) : 0;
      cout << b * r % MOD << endl;
    } else {
      cout << (i == 1 ? 1 : 0) << endl;
    }
  }
}