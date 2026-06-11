#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  ll ans = 1e12;

  ll k = 0;

  for (ll i = 1; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      ll yaku = n / i;
      ll dx = yaku - 1;
      ll dy = i - 1;
      ans = min(ans, dx + dy);
    }
  }

  cout << ans;
}
