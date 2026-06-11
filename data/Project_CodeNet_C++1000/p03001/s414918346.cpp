#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  double o1 = 0.5 * w * h;
  int o2;
  if (2 * x == w && 2 * y == h) o2 = 1;
  else o2 = 0;
  printf("%.1f %d\n", o1, o2);
  return 0;
}