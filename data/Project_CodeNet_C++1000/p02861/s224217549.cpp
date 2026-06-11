#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <cmath>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> D(N, std::pair<int, int>(0, 0));

  for (int i = 0; i < N; i++) {
    std::cin >> D[i].first;
    std::cin >> D[i].second;
  }
  std::sort(D.begin(), D.end());

  int p = 0;
  double ad = 0;
  do {
    p++;
    double d = 0;
    for (int i = 1; i < D.size(); i++) {
      auto pp = D[i - 1];
      auto cp = D[i];
      d += std::sqrt(std::pow(pp.first - cp.first, 2.0) + std::pow(pp.second - cp.second, 2.0));
    }
    ad += d;
  } while(std::next_permutation(D.begin(), D.end()));

  std::cout << std::setprecision(10) << ad / p << std::endl;

  return 0;
}
