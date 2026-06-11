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

int main()
{
  ll mod = 998244353;
  ll N;
  cin >> N;
  vector<ll> D(N, 0);
  ll M = 0;
  for (ll i = 0; i < N; ++i) {
    ll d;
    cin >> d;
    if (i == 0) {
      if (d != 0) {
        cout << 0 << "\n";
        return 0;
      }
    }
    D.at(d) += 1;
    M = max(d, M);
  }
  if (D.at(0) > 1) {
    cout << 0 << "\n";
    return 0;
  }
  ll ans = 1;
  for (ll i = 0; i < M; ++i) {
    ans = (ans * modpow(D.at(i), D.at(i + 1), mod)) % mod;
  }
  cout << ans << "\n";
}
