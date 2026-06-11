#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

// x^n
ll mod_pow(ll x, ll n) {
  if (n == 0) return 1;
  ll res = mod_pow(x * x % MOD, n / 2);
  if (n & 1) res = res * x % MOD;
  return res;
}

// x^{-1}
ll mod_inv(ll x) { return mod_pow(x, MOD - 2); }

vector<ll> fact;
vector<ll> fact_inv;

void init_fact(int n) {
  fact.resize(n + 1);
  fact_inv.resize(n + 1);
  fact[0] = fact_inv[0] = 1;
  for (int i = 0; i < n; ++i) {
    fact[i + 1] = fact[i] * (i + 1) % MOD;
    fact_inv[i + 1] = fact_inv[i] * mod_inv(i + 1) % MOD;
  }
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = mod_pow(2, n);
  ans = (ans + MOD - 1) % MOD;
  ll sub1 = 1, sub2 = 1;
  for (int i = 0; i < a; ++i) {
    sub1 = (sub1 * (n - i)) % MOD;
    sub1 = (sub1 * mod_inv(a - i)) % MOD;
  }
  for (int i = 0; i < b; ++i) {
    sub2 = (sub2 * (n - i)) % MOD;
    sub2 = (sub2 * mod_inv(b - i)) % MOD;
  }
  ans = (ans + MOD - sub1) % MOD;
  ans = (ans + MOD - sub2) % MOD;
  cout << ans << endl;
  return 0;
}