#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define INF 1000000000000
typedef long long ll;

int main()
{
  ll n, sum = 0;
  cin >> n;
  vector<ll> a(n + 1), b(n);

  REP(i, n + 1)
  {
    cin >> a[i];
  }
  REP(i, n)
  {
    cin >> b[i];
  }
  REP(i, n)
  {
    if (a[i] >= b[i])
    {
      sum += b[i];
    }
    else
    {
      sum += a[i];
      b[i] -= a[i];
      if (a[i + 1] >= b[i])
      {
        sum += b[i];
        a[i + 1] -= b[i];
      }
      else
      {
        sum += a[i + 1];
        a[i + 1] = 0;
      }
    }
  }
  cout << sum << endl;
}