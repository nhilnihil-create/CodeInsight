#include <iostream>
#include <cstdio>
#include <cmath>

const int N = 1000;

int main(void) {
  int data[N] = {0};
  int n = 0;

  
  std::cin >> n;

  while (n != 0) {
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
      std::cin >> data[i];

      sum += data[i];
    }

    double m = sum / n;

    sum = 0.0;

    for (int i = 0; i < n; i++) {
      sum += std::pow(data[i] - m, 2.0);
    }

    double sd = std::sqrt(sum / n);

    printf("%f\n", sd);

    std::cin >> n;
  }  
  
  return 0;
}