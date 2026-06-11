#include <bits/stdc++.h>

int main() {
  int n; std::cin >> n;
  int odd_num = (n + 2 - 1) / 2;
  double prob = odd_num / (double)n;
  printf("%.10lf\n", prob);
  
  return 0;
}