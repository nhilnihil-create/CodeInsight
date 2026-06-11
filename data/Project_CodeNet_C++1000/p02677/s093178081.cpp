#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int A, B, H, M;
  cin >> A >> B >> H >> M;
  
  double th = double(H*60+M)/720 * 2*M_PI;
  double tm = double(M)/60 * 2*M_PI;
  double xh = A*cos(th), yh = A*sin(th);
  double xm = B*cos(tm), ym = B*sin(tm);
  double dx = xh-xm, dy = yh-ym;
  double ans = sqrt(dx*dx + dy*dy);
  printf("%.10f\n", ans);
  return 0;
}