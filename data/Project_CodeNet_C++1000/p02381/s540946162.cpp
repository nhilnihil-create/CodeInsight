#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

double standardDeviation(std::vector<double> &nums) {
  double average = std::accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
  double sum =
      std::accumulate(nums.begin(), nums.end(), 0.0,
                      [&average](const double &init, const double &elm) {
                        return init + pow(elm - average, 2.0);
                      });
  double variance = sum / nums.size();
  return sqrt(variance);
}

int main() {
  int n;
  while (std::cin >> n) {
    if (n == 0) return 0;

    std::vector<double> nums;
    while (n-- != 0) {
      double buf;
      std::cin >> buf;
      nums.push_back(buf);
    }
    std::cout << std::fixed << std::setprecision(5) << standardDeviation(nums)
              << std::endl;
  }
}

