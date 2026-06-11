#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll MOD = 1000000007;

ll mod_pow(ll x, ll n)
{
  ll ret = 1;
  while (n > 0)
  {
    if (n & 1)
      ret = ret * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return ret;
}

vector<ll> fact;
vector<ll> ifact;

void mod_ifact(ll n)
{
  fact.resize(n + 1);
  fill(fact.begin(), fact.end(), 1);
  ifact.resize(n + 1);
  fill(ifact.begin(), ifact.end(), 0);
  for (ll i=1; i<n+1; i++)
    fact[i] = fact[i-1] * i % MOD;
  ifact[n] = mod_pow(fact[n], MOD - 2);
  for (ll i=n; i>0; i--)
    ifact[i-1] = ifact[i] * i % MOD;
}

ll mod_comb(ll n, ll k)
{
  if (k < 0 || k > n)
    return 0;
  return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int main()
{
  int n, k;
  cin >> n >> k;
  mod_ifact(n);
  for (int i=1; i<=k; i++)
    printf("%lld\n", mod_comb(k - 1, i - 1) * mod_comb(n - k + 1, i) % MOD);
  return 0;
}