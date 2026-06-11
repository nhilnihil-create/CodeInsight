#include <bits/stdc++.h>

double sub1(int* x, int* y, int n, int p) {
  double temp = 0;
  for(int i = 0; i < n; ++i) {
    temp += pow(abs(x[i]-y[i]), p);
  }
  return pow(temp, 1.0/p);
}
  

int main() {

  int x[128];
  int y[128];

  int N;
  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> x[i];
  }
  for(int i = 0; i < N; ++i) {
    std::cin >> y[i];
  }

  printf("%.10lf\n", sub1(x, y, N, 1));
  printf("%.10lf\n", sub1(x, y, N, 2));
  printf("%.10lf\n", sub1(x, y, N, 3));

  double ans = 0;
  for(int i = 0; i < N; ++i) {
    if( ans < abs(x[i]-y[i]) ) {
      ans = abs(x[i]-y[i]);
    }
  }
  printf("%.10lf\n", ans);
  
  return 0;
}