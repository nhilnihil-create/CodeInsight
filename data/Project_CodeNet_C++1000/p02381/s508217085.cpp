#include <iostream>
#include <math.h>
#include <iomanip>


#define PI 3.14159265


double standard_deviation(double *s, double m, double n) {
  double sum_ = 0;
  for (int i = 0; i < n; i ++) {
    sum_ += pow((s[i] - m), 2);
  }
  return sum_ / n;
}

int main() {
  double n;
  double s[1000] = {0};
  double m = 0;

  while (true) {
    m = 0;
    std::cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; i ++) {
      std::cin >> s[i];
      m += s[i];
    }
    m /= n;

    std::cout << std::fixed << std::setprecision(8)
      << sqrt(standard_deviation(s, m, n)) << std::endl;
  }

  return 0;
}

