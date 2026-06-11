#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define mset(s, _) memset(s, _, sizeof s)
#define ALL(a) (a).begin(), (a).end()
using namespace std;

int main(void) {
  static const double pi = 3.141592653589793238;
  int A, B, H, M;
  cin >> A >> B >> H >> M;

  double thetaA = (60.0 * H + M) / 2.0;
  double thetaB = M * 6.0;

  // cout << thetaA << " " << thetaB << endl;
  // cout << thetaA - thetaB << endl;
  // cout << pi * (thetaA - thetaB) / 180.0 << endl;

  double ans =
      sqrt(A * A + B * B - 2 * A * B * cos(pi * (thetaA - thetaB) / 180.0));

  printf("%.15f", ans);
  return 0;
}
