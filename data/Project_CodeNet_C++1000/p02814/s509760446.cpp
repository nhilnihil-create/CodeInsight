#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fail()
{
  cout << 0 << '\n';
  exit(0);
}

int f(int x)
{
  int res = 0;

  while (x % 2 == 0) {
    x /= 2;
    ++res;
  }

  return res;
}

ll lcm(ll x, ll y)
{
  return x / __gcd(x, y) * y;
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 0; i < n; ++i) {
    if (a[i] & 1) fail();
    a[i] /= 2;
  }

  int d = f(a[0]);
  for (int i = 1; i < n; ++i) if (f(a[i]) != d) fail();

  ll l = 1;
  for (int i = 0; i < n; ++i) l = lcm(l, a[i]);

  ll ans = m / l;
  cout << (ans + 1) / 2 << '\n';

  return (0);
}