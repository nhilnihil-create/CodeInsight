#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  double ans = (double)w*h/2;
  int num = (w==x*2 && h==y*2) ? 1 : 0;
  printf("%.10f %d\n", ans, num);

  return 0;
}