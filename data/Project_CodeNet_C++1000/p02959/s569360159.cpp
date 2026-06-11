#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  for (ll i = 0; i < n + 1; i++)
  {
    cin >> a[i];
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++)
  {
    ll b = 0;
    cin >> b;
    if (a[i] >= b)
    {
      ans += b;
    }
    else
    {
      ans += a[i];
      if (a[i + 1] > b - a[i])
      {
        ans += b - a[i];
        a[i + 1] -= b - a[i];
      }
      else
      {
        ans += a[i + 1];
        a[i + 1] = 0;
      }
    }
  }
  cout << ans << endl;
}
