#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int n, k;
vector<int> a;

bool f(ll c)
{
  vector<ll> m(n);
  ll msum = 0;
  rep(j, n)
  {
    m[j] = a[j] % c;
    msum += m[j];
  }
  sort(m.begin(), m.end());
  ll msum2 = 0;
  for (int j = m.size() - 1; j >= 0; j--)
  {
    msum -= m[j];
    msum2 += c - m[j];
    if (max(msum, msum2) <= k)
    {
      cout << c << endl;
      return true;
    }
  }
  return false;
}

int main()
{
  cin >> n >> k;
  a.resize(n);
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
      if (f(s / i))
        return 0;
      c.push_back(i);
    }
  for (int i = c.size() - 1; i >= 0; i--)
    if (f(c[i]))
      return 0;
  return 0;
}