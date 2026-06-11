#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <time.h>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for (i = 0; i < n; i++)
#define P pair<int, int>

ll INF = 1000000000000000000;

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 0; i < n + 1; i++)
  {
    cin >> a[i];
  }

  if (n == 0)
  {
    if (a[0] == 1)
    {
      cout << 1 << endl;
      return 0;
    }
    else
    {
      cout << -1 << endl;
      return 0;
    }
  }

  vector<ll> d(n + 1);
  d[n] = a[n];
  for (int i = n - 1; i >= 0; i--)
  {
    d[i] = (d[i + 1] + 1) / 2 + a[i];
  }
  if (d[0] > 1)
  {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> cum(n + 1);
  cum[n] = a[n];
  for (int i = n - 1; i >= 0; i--)
  {
    cum[i] = cum[i + 1] + a[i];
  }

  vector<ll> b(n + 1);
  b[0] = 1;
  for (int i = 1; i < n + 1; i++)
  {
    b[i] = 2 * (b[i - 1] - a[i - 1]);
    if (b[i] >= INF)
    {
      b[i] = INF;
    }
  }

  vector<ll> res(n + 1);
  for (int i = 0; i < n + 1; i++)
  {
    res[i] = min(cum[i], b[i]);
  }

  ll ans = 0;
  for (int i = 0; i < n + 1; i++)
  {
    ans += res[i];
  }

  cout << ans << endl;
}
