#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, H, M;
  cin >> A >> B >> H >> M;
  long double m = 360.0 / 60.0 * M;
  long double h = 360.0 / 12.0 * H + 30.0 / 60.0 * M;
  long double tmp = max(m, h) - min(m, h);
  tmp = min(tmp, 360.0 - tmp);
  tmp *= M_PI / 180;
  cout << fixed << setprecision(9) << sqrt(A * A + B * B - 2 * A * B * cos(tmp)) << "\n";
}