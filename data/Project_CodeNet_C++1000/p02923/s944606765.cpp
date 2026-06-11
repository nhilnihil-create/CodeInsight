#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  vector<ll> h(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  ll ans = 0;
  ll buf = 0;

  for (ll i = 0; i < n - 1; i++)
  {
    if (h[i] >= h[i + 1])
    {
      buf++;
      ans = max(ans, buf);
    }
    else
    {
      buf = 0;
    }
  }
  cout << ans << endl;
}
