#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
using namespace std;

int main() {
  int n;
  int x[1000], y[1000];
  double a;
  double d1 = 0;
  double d2 = 0;
  double d3 = 0;
  double dm = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }

  for (int i = 0; i < n; i++) {
    a = abs(x[i] - y[i]);
    d1 += a;
    d2 += a * a;
    d3 += a * a * a;
    if (a > dm) dm = a;
  }

  printf("%f\n", d1);
  printf("%f\n", sqrt(d2));
  printf("%f\n", pow(d3, 1.0 / 3.0));
  printf("%f\n", dm);

  return 0;
}