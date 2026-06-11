#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  for (ll i = sqrt(n); i > 0; --i) {
    if (n % i == 0) {
      cout << (n / i) + i - 2 << endl;
      return (0);
    }
  }

  return (0);
}
