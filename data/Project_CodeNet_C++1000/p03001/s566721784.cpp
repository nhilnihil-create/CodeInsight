#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int W, H, x, y;
  cin >> W >> H >> x >> y;

  double ans = (double) W * H / 2.0;
  int center;
  if (W % 2 == 0 && H % 2 == 0 && W / 2 == x && H / 2 == y) center = 1;
  else center = 0;

  cout << ans << " " << center << endl;

  return 0;
}