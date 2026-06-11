#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, k;
  cin >> n >> k;
  ll ans = 1e9;
  while (1)
  {
    ll buf = min(abs(n - k), n % k);
    n = buf;
    if (ans == n)
    {
      break;
    }
    ans = n;
  }
  cout << ans << endl;
}

