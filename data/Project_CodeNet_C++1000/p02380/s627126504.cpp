#include <cmath>
#include <iostream>
using namespace std;

#define r(c) ((c) * M_PI / 180)

int main() {
  double a, b, C, S, L, h;

  cin >> a >> b >> C;

  h = b * sin(r(C));
  L = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(r(C)));
  S = a * h / 2;

  cout << fixed << S << endl << L << endl << h << endl;

  return 0;
}