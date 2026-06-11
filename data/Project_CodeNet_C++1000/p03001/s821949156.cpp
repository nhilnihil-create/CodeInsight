#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  double w, h, x, y;
  cin >> w >> h >> x >> y;
  int a;
  if (2 * x == w && 2 * y == h)
    a = 1;
  else
    a = 0;
  printf("%.6lf %d\n", (w * h) / 2, a);
  return 0;
}