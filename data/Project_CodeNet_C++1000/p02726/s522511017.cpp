#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

int main()
{
  int N, X, Y;
  cin >> N >> X >> Y;
  X -= 1;
  Y -= 1;

  map<ll, ll> ans;
  REP(i, N)
  {
    FOR(j, i + 1, N - 1)
    {
      ll d1 = j - i;
      ll d2 = abs(X - i) + 1 + abs(Y - j);
      ans[min(d1, d2)]++;
    }
  }

  FOR(i, 1, N - 1)
  {
    cout << ans[i] << endl;
  }

  return 0;
}