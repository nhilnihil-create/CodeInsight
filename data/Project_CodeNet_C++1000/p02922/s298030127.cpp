#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int calc_tap(double a, double b) {
  double n = ceil(max(b - a, 0.0) / (a - 1.0)) + 1.0;
  return (int)n;
}

int main() {
  double a;
  double b;
  cin >> a >> b;

  int res;
  if (b == 1) {
    res = 0;
  } else {
    res = calc_tap(a, b);
  }
  cout << res << endl;
}
