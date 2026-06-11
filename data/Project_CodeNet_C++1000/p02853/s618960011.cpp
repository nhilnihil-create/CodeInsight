#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int X, Y;
  cin >> X >> Y;
  int ans = 0;

  switch (X) {
  case 3:
    ans += 100000;
    break;
  case 2:
    ans += 200000;
    break;
  case 1:
    ans += 300000;
    break;
  default:
    break;
  }

  switch (Y) {
  case 3:
    ans += 100000;
    break;
  case 2:
    ans += 200000;
    break;
  case 1:
    ans += 300000;
    break;
  default:
    break;
  }

  if (X == 1 && Y == 1) {
    ans += 400000;
  }
  cout << ans << endl;

  return 0;
}
