#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int n;
ll k;
vector<ll> a, f;

bool chk(ll mid)
{
  ll count = 0;
  rep(i, n)
  {
    ll t = a[i] * f[i];
    if (mid < t)
    {
      count += (t - mid + f[i] - 1) / f[i];
      if (count > k)
        return false;
    }
  }
  return true;
}

int main()
{
  cin >> n >> k;
  a.resize(n);
  f.resize(n);
  rep(i, n)
    cin >> a[i];
  rep(i, n)
    cin >> f[i];
  sort(a.begin(), a.end());
  sort(f.begin(), f.end());
  reverse(f.begin(), f.end());
  ll l = -1, r = 1e12;
  while (l + 1 < r)
  {
    ll mid = (l + r) / 2;
    if (chk(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
  return 0;
}