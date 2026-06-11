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

  vector<ll> a(n);

  REP(i, n)
  {
    cin >> a[i];
  }

  REP(i, n - 1)
  {
    if (a[i + 1] < a[i])
    {
      sum += a[i] - a[i + 1];
      a[i + 1] = a[i];
    }
  }
  cout << sum << endl;
}