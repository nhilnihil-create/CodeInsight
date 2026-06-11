#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void) {
  int a,b,C;
  double S,L,h;
  cin >> a >> b >> C;
  S = 1.0 / 2.0 * a * b * sin(M_PI / 180 * C);
  L = a + b + sqrt(a * a + b * b - 2.0 * a * b * cos(M_PI / 180 * C));
  h = b * sin(M_PI / 180 * C);
  cout << fixed << setprecision(9) << S << endl << L << endl << h << endl;
  return 0;
}