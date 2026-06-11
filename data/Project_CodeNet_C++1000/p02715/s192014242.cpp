#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;
using ll = long long;

ll modpow(ll a, ll p) {
  if (p == 0) return 1;
  ll r = modpow(a, p/2);
  r *= r;
  r %= mod;
  if (p & 1) r *= a;
  r %= mod;
  return r;
}

int main() {
  ll N, K; cin >> N >> K;
  vector<ll> cnt(K+1);
  ll res = 0;
  for (int i = K; i > 0; i--) {
    ll a = K / i;
    a = modpow(a, N);
    for (int j = i + i; j <= K; j += i) {
      a += mod - cnt[j];
    }
    cnt[i] = a % mod;
    res += cnt[i] * i;
    res %= mod;
  }
  cout << res << endl;
}