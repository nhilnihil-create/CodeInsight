#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main()
{
  int n;
  ll ans = 1, s = 1000000000000000000;
  cin >> n;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> ans;
    a[i] = ans;
    if (ans == 0)
    {
      cout << 0;
      return 0;
    }
  }
  ans = 1;
  rep(i, n)
  {
    if (a[i] > s / ans)
    {
      cout << -1;
      return 0;
    }
    ans *= a[i];
  }
  cout << ans;
}
