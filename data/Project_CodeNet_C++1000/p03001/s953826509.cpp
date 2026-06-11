#include <bits/stdc++.h>
using namespace std;

int main()
{
  long double W, H, x, y;
  cin >> W >> H >> x >> y;
  cout << fixed << setprecision(6) << (H * W) / 2.0 << ' ';
  if ((int64_t)W % 2 == 0 && (int64_t)H % 2 == 0 && W / 2 == x && H / 2 == y)
  {
    cout << 1 << endl;
  }
  else
  {
    cout << 0 << endl;
  }
}