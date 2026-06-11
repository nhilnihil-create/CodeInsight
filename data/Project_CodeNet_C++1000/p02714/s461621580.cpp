#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
using namespace std;
typedef long long ll;

int main()
{
  ll N;
  cin >> N;

  string S;
  cin >> S;

  ll ans = 0;
  ll r, g, b;
  r = g = b = 0;
  REP(i, N)
  {
    switch (S[i])
    {
    case 'R':
      r++;
      break;
    case 'G':
      g++;
      break;
    case 'B':
      b++;
      break;
    }
  }

  ans = r * g * b;
  FOR(i, 0, N - 3)
  {
    FOR(j, i + 1, N - 2)
    {
      ll k = 2 * j - i;
      if (k < N && S[i] != S[j] && S[j] != S[k] && S[k] != S[i])
        ans--;
    }
  }

  cout << ans << endl;

  return 0;
}