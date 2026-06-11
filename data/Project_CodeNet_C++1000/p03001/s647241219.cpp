#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  double w, h;
  int x, y;
  cin >> w >> h >> x >> y;
  double s = w*h/2;
  int ans;
  if (w == 2*x && h == 2*y) ans = 1;
  else ans = 0;
  printf("%lf %d\n", s, ans);
  return 0;
}