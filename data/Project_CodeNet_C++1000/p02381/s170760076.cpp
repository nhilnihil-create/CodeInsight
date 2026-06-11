#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

int main() {
  int n;

  while(std::cin >> n) {
    if(n == 0) break;
    std::vector<int> score(n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
      std::cin >> score[i];
      sum += score[i];
    }
    double average = double(sum) / double(n);
    double alpha = 0;
    for(int i = 0; i < n; ++i) {
      alpha += (score[i] - average) * (score[i] - average);
    }
    alpha = sqrt(alpha / n);
    printf("%.4f\n", alpha);
  }

  return 0;
}