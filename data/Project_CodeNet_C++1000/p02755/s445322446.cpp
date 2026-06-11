#include <bits/stdc++.h>
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
using namespace std;
typedef long long ll;

int main()
{
  ll A, B;
  cin >> A >> B;

  FOR(c, 1, 1000)
  {
    if ((ll)(c * 0.08) == A && (ll)(c * 0.1) == B)
    {
      cout << c << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}