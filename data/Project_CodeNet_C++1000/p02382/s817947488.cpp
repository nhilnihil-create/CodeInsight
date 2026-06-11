#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> x(n);
  std::vector<int> y(n);
  for(int i = 0; i < n; ++i) {
    std::cin >> x[i];
  }
  for(int i = 0; i < n; ++i) {
    std::cin >> y[i];
  }

  double Manhattan = 0.0;
  for(int i = 0; i < n; ++i) {
    Manhattan += std::abs(x[i] - y[i]);
  }

  double Euclidean = 0.0;
  for(int i = 0; i < n; ++i) {
    Euclidean += std::abs(x[i] - y[i]) * std::abs(x[i] - y[i]);
  }
  Euclidean = sqrt(Euclidean);

  double Euclidean_p3 = 0.0;
  for(int i = 0; i < n; ++i) {
    Euclidean_p3 += std::abs(x[i] - y[i]) * std::abs(x[i] - y[i]) * std::abs(x[i] - y[i]);
  }
  Euclidean_p3 = pow(Euclidean_p3, double(1.0/3.0));

  double Chebyshev = std::abs(x[0] - y[0]);
  for(int i = 1; i < n; ++i) {
    double tmp = std::abs(x[i] - y[i]);
    if(Chebyshev < tmp) {
      Chebyshev = tmp;
    }
  }

  printf("%.5f\n", Manhattan);
  printf("%.5f\n", Euclidean);
  printf("%.5f\n", Euclidean_p3);
  printf("%.5f\n", Chebyshev);

  return 0;
}