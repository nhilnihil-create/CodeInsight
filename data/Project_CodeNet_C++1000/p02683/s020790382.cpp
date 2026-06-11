#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  ll x;
  cin >> n >> m >> x;
  vector<ll> c(n);
  vector<vector<ll>> a(n, vector<ll>(m));
  for (int i = 0; i < n; i++)
  {
    cin >> c[i];
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  ll ans = 1e9;
  bool ng = false;
  for (int bit = 0; bit < (1 << n); bit++)
  {
    vector<int> test;
    for (int i = 0; i < n; i++)
    {
      if (bit & (1 << i))
      {
        test.push_back(i);
      }
    }
    ll ctest = 0;
    vector<ll> atest(m);
    for (int i = 0; i < test.size(); i++)
    {
      ctest += c[test[i]];
      for (int j = 0; j < m; j++)
      {
        atest[j] += a[test[i]][j];
      }
    }
    bool ok = true;
    for (int i = 0; i < m; i++)
    {
      if (atest[i] < x)
      {
        ok = false;
      }
    }
    if (ok)
    {
      ans = min(ans, ctest);
      ng = true;
    }
  }
  if (ng)
  {
    cout << ans << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}
