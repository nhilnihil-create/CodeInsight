#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c_deg;
  double s, l, h, rad, PI = acos(-1);
  cin >> a >> b >> c_deg;
  rad = c_deg * PI / 180;
  s = 0.5 * a * b * sin(rad);
  l = a + b + (sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(rad)));
  h = b * sin(rad);

  cout << fixed << setprecision(8);
  cout << s << endl;
  cout << l << endl;
  cout << h << endl;
  return 0;
}
