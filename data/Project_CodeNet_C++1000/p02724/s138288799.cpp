#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define INF 1000000000000
typedef long long ll;

int main()
{
  int x, ans = 0;
  cin >> x;

  if (x >= 500)
  {
    ans += int(x / 500) * 1000;
    x %= 500;
  }
  if (x >= 5)
  {
    ans += int(x / 5) * 5;
  }

  cout << ans << endl;
}