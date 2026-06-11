#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, m;
  cin >> n >> m;
  ll sum = 0;
  for (ll i = 0; i < m; i++)
  {
    ll a;
    cin >> a;
    sum += a;
  }
  ll ans = n - sum;
  if (ans >= 0)
  {
    cout << ans << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}
