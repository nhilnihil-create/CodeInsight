#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.141592653589
using namespace std;

int main() {
  double a, b, C, S, L, h;
  cin >> a >> b >> C;
  S = 0.5 * a * b * sin(C * PI / 180);
  L = a + b + pow(a * a + b * b - 2 * a * b * cos(C * PI / 180), 0.5);
  h = 2 * S / a;
  cout << fixed << setprecision(10) << S << endl << L << endl << h << endl;
}

