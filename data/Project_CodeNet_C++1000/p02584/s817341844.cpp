#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define INF 1000000000000
typedef long long ll;

int main()
{
  ll x, k, d, times, ans;
  cin >> x >> k >> d;
  x = abs(x);
  times = x / d;
  if (k <= times)
  {
    ans = x - k * d;
  }
  else
  {
    k -= times;
    if (k % 2 == 0)
    {
      ans = x % d;
    }
    else
    {
      ans = min(abs(x % d + d), abs(x % d - d));
    }
  }

  cout << ans << endl;
}