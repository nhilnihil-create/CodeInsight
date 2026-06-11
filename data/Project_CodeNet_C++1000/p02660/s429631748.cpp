#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main()
{
  ll n, ans = 0;
  cin >> n;
  vector<pair<ll, ll>> a;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i != 0)
      continue;
    ll e = 0;
    while (n % i == 0)
    {
      e++;
      n /= i;
    }
    a.push_back({i, e});
  }
  if (n != 1)
    a.push_back({n, 1});
  for (auto p : a)
  {
    for (int i = 1;; i++)
    {
      if (p.second >= i * (i + 1) / 2)
        ans++;
      else
        break;
    }
  }
  cout << ans;
}
