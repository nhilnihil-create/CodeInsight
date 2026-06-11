#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> prime_factorize(ll n)
{
  vector<pair<ll, ll>> res;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i != 0)
    {
      continue;
    }
    ll ex = 0;
    while (n % i == 0)
    {
      ex++;
      n /= i;
    }
    res.push_back({i, ex});
  }
  if (n != 1)
  {
    res.push_back({n, 1});
  }
  return res;
}

int main()
{
  ll n;
  cin >> n;
  const auto &res = prime_factorize(n);
  ll ans = 0;
  for (ll i = 0; i < res.size(); i++)
  {
    ll x = res[i].second;
    ll b = 1;
    while (b <= x)
    {
      x -= b;
      b++;
      ans++;
    }
  }
  cout << ans << endl;
}
