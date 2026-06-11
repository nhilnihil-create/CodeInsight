#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  ll v = 0, e = 0;

  cin >> n;
  for (ll i = 1; i <= n; ++i) v += i * (n - i + 1);
  for (int i = 0; i < n-1; ++i) {
    ll l, r;
    cin >> l >> r;

    if (l > r) swap(l, r);
    e += l * (n - r + 1);
  }
  
  cout << v - e << endl;

  return (0);
}