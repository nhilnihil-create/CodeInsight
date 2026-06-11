#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  using std::vector;  
  int n;
  std::cin >> n;
  vector<vector<int>> a(2, vector<int>(n, 0));
  
  // input vectors x and y
  for (int i = 0; i < n; i++) std::cin >> a[0][i];
  for (int i = 0; i < n; i++) std::cin >> a[1][i];
  
  // p = 1, 2, 3
  for (int p = 1; p <= 3; p++) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
      sum += pow(abs(a[0][i]-a[1][i]), p);
    }
    printf("%f\n", pow(sum, 1.0/p));
  }
  
  // p is infinite
  double maxd = 0;
  for (int i = 0; i < n; i++) {
    double d = abs(a[0][i] - a[1][i]);
    if (d > maxd) maxd = d;
  }
  printf("%f\n", maxd);
  
  return 0;
}