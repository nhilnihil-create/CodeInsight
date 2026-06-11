#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  double w, h, x, y;
  cin >> w >> h >> x >> y;

  double rec = 0.5 * w * h;

  int ans = 0;
  if (2 * x == w && 2 * y == h)
  {
    ans = 1;
  }
  cout << fixed << setprecision(6) << rec << " " << ans << endl;
}
