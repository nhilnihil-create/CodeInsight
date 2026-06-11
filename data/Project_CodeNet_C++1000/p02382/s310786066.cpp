#include <math.h>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int xs[100] = {};
  int ys[100] = {};
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> ys[i];
  }
  double sum1 = 0.0, sum2 = 0.0, sum3 = 0.0;
  double d = 0.0, max = 0.0;
  for (int i = 0; i < n; i++) {
    d = abs((xs[i] - ys[i]));
    sum1 += d;
    sum2 += (d * d);
    sum3 += (d * d * d);
    if (max < d) {
      max = d;
    }
  }
  printf("%.5f\n", sum1);
  printf("%.5f\n", sqrt(sum2));
  printf("%.5f\n", pow(sum3, 1.0 / 3.0));
  printf("%.5f\n", max);
  return 0;
}
