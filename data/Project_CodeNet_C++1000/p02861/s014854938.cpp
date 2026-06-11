#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

int main() {
  int n; std::cin >> n;
  std::vector<int> x(n);
  std::vector<int> y(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i];
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int dx = x[i]-x[j];
      int dy = y[i]-y[j];
      sum += sqrt((double)dx*dx + (double)dy*dy);
    }
  }
  double ans = sum * 2 / (double)n;
  printf("%.10lf\n", ans);
  
  return 0;
}