#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;
const ll MOD = 1000000007;
ll modpow(ll a, ll n, ll mod)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll modinv(ll a, ll mod)
{
  return modpow(a, mod - 2, mod);
}

ll modnCr(ll n, ll r, ll mod)
{
  ll ans = 1;
  FOR(i, 1, n + 1)
  {
    ans = (ans * i) % mod;
  }
  ll inv = 1;
  FOR(i, 1, r + 1)
  {
    inv = (inv * i) % mod;
  }
  FOR(i, 1, n - r + 1)
  {
    inv = (inv * i) % mod;
  }
  ans = (ans * modinv(inv, mod)) % mod;
  return ans;
}

int main()
{
  int n;
  string s;
  cin >> n >> s;
  if (s[0] == 'W' || s[2 * n - 1] == 'W')
  {
    cout << 0 << endl;
    return 0;
  }

  // l:1, r:-1
  int lr[200000] = {};
  ll cumr[200000] = {};
  ll cuml[200000] = {};
  cumr[0] = 0;
  cuml[0] = 1;
  lr[0] = 1;

  FOR(i, 1, 2 * n)
  {
    cumr[i] = cumr[i - 1];
    cuml[i] = cuml[i - 1];
    if (s[i - 1] == s[i])
    {
      lr[i] = -1 * lr[i - 1];
    }
    else
    {
      lr[i] = lr[i - 1];
    }

    if (lr[i] == 1)
    {
      cuml[i]++;
    }
    else
    {
      cumr[i]++;
    }
  }
  if (cumr[2 * n - 1] != cuml[2 * n - 1])
  {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1;
  REP(i, 2 * n)
  {
    if (lr[i] == 1)
      continue;
    ans = (ans * (cuml[i - 1] - cumr[i - 1])) % MOD;
  }

  FOR(i, 1, n + 1)
  {
    ans = (ans * i) % MOD;
  }

  cout << ans << endl;
}
