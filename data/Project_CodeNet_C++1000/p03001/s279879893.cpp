#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  ll W, H, x1, y1;
  cin >> W >> H >> x1 >> y1;

  ll x2 = abs(W - x1);
  ll y2 = abs(H - y1);

  ll x_diff = max(x1, x2) - min(x1, x2);
  ll y_diff = max(y1, y2) - min(y1, y2);

  if (x_diff == 0 && y_diff == 0) {
    printf("%.6f %d\n", W * H / 2.0, 1);
    return 0;
  }

  printf("%.6f %d\n", W * H / 2.0, 0);
  return 0;
}
