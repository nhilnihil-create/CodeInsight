#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  ll s = 0;
  rep(i, n)
  {
    cin >> a[i];
    s += a[i];
  }
  vector<ll> c;
  for (ll i = 1; i * i <= s; i++)
    if (s % i == 0)
    {
      c.push_back(i);
      c.push_back(s / i);
    }
  sort(c.begin(), c.end(), greater<ll>());
  for (auto i : c)
  {
    vector<ll> m(n);
    ll msum = 0;
    rep(j, n)
    {
      m[j] = a[j] % i;
      msum += m[j];
    }
    sort(m.begin(), m.end());
    ll msum2 = 0;
    for (int j = m.size() - 1; j >= 0; j--)
    {
      msum -= m[j];
      msum2 += i - m[j];
      if (max(msum, msum2) <= k)
      {
        cout << i << endl;
        return 0;
      }
    }
  }
  return 0;
}