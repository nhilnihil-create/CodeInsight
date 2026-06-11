#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  ll ans = a[0];
  for (int i = 1; i < n; i++)
  {
    ans ^= a[i];
  }
  if (ans == 0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}