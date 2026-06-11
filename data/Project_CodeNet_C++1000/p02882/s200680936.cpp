#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  double h = x / (a * a);
  if (h * 2 <= b) {
    double A = h * a * 2 / b;
    cout << fixed << setprecision(12) << atan2(b, A) / M_PI * 180 << endl;
  } else {
    double A = h * 2 - b;
    cout << fixed << setprecision(12) << atan2(b - A, a) / M_PI * 180 << endl;
  }
}
