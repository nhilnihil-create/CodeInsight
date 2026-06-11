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

int main() {
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  vector<ll> cnt(k + 1);
  for (int i = k; i >= 1; --i) {
    cnt[i] = mod_pow(k / i, n);
    for (int j = 2; i * j <= k; ++j) {
      cnt[i] = (cnt[i] - cnt[i * j] + MOD) % MOD;
    }
    ll res = (cnt[i] * i) % MOD;
    ans = (ans + res) % MOD;
  }
  cout << ans << endl;
  return 0;
}