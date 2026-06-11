#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

long double A, B, H, M;
long double angle;

int main(){
  cin >> A >> B >> H >> M;
  angle = (30 * H) + (30 * M / 60) - (6 * M);
  // if (angle > 180) angle -= 180;
  long double radian;
  radian = (angle / 180) * M_PI;
  long double ans;
  ans = sqrtl((A*A + B*B) - (2*A*B*cosl(radian)));
  cout << fixed << setprecision(20);
  cout << ans << endl;
}
