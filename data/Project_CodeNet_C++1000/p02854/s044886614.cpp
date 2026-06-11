#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  long sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a.at(i);
    sum += a.at(i);
  }

  if (n == 2) {
    std::cout << std::abs(a.at(0) - a.at(1)) << std::endl;
    return 0;
  }

  long half = 0;
  long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (sum <= half * 2) {
      ans = half * 2 - sum;
      if (0 < i) {
        ans = std::min(ans, sum - (half - a.at(i - 1)) * 2);
      }
      break;
    }
    half += a.at(i);
  }

  std::cout << ans << std::endl;
}
