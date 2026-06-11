#include <iostream>
#include <math.h>
#include <iomanip>


double absolute(double x) {
  return (x < 0) ? (x * -1) : x;
}

double chebyshev_distance(double *x, double *y, int size) {
  double dis = -1, temp;
  for (int i = 0; i < size; i ++) {
    temp = absolute(x[i] - y[i]);
    if (temp > dis) dis = temp;
  }
  return dis;
}

double distance(double *x, double *y, int size, int p) {
  double summation = 0;
  for (int i = 0; i < size; i ++) {
    summation += pow(absolute(x[i] - y[i]), p);
    // std::cout << " " << summation << " " << x[i] << " " << y[i] << std::endl;
  }
  return pow(summation, 1 / (double)p);
}


int main() {
  double x[1000], y[1000];
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i ++) {
    std::cin >> x[i];
  }
  for (int i = 0; i < n; i ++) {
    std::cin >> y[i];
  }
  
  for (int i = 1; i <= 3; i ++) {
    std::cout << std::fixed << std::setprecision(8)
      << distance(x, y, n, i) << std::endl;
  }
  std::cout << chebyshev_distance(x, y, n) << std::endl;

  return 0;
}

