#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  vector<ll> p(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> p[i];
  }

  ll minn = 1e5 * 2;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (minn >= p[i])
    {
      ans++;
    }
    minn = min(minn, p[i]);
  }

  cout << ans << endl;
}
