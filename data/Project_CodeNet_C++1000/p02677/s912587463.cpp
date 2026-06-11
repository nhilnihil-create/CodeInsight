#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = acos(-1);

int main(void){
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double th, tm;
  th = (h*60 + m) / 720 *2*PI;
  tm = m / 60 *2*PI;
  double xh, yh, xm, ym;
  xh = a*sin(th); yh = a*cos(th);
  xm = b*sin(tm); ym = b*cos(tm);
  double dx, dy;
  dx = xh - xm;
  dy = yh - ym;
  double ans = sqrt(dx*dx + dy*dy);
  printf("%.12f",ans);
  return 0;
}