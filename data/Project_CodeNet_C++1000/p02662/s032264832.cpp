#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

//=============modpow============================
ll modpow(ll a, ll n, ll mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
//=================================================

//=============modinv============================
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
//=================================================

int main() {
  ll mod = 998244353;
  ll two_inv = modinv(2, mod);
  ll N, S;
  cin >> N >> S;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  vector<ll> dp(S + 1);
  dp.at(0) = modpow(2, N, mod);
  for (ll i = 0; i < N; ++i) {
    vector<ll> temp = dp;
    ll a = A.at(i);
    for (ll i = 0; i <= S - a; ++i) {
      dp.at(i + a) += (temp.at(i) * two_inv) % mod;
      dp.at(i + a) %= mod;
    }
  }
  cout << dp.at(S) << "\n";
}
