#include <iostream>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  int h[n];
  for (int i = 0; i < n; i++) {
    std::cin >> h[i];
  }

  for (int i = 1; i < n; i++) {
    if (h[i - 1] <= h[i] - 1) {
      h[i]--;
    } else if (h[i - 1] <= h[i]) {
      continue;
    } else {
      std::cout << "No" << "\n";
      return 0;
    }
  }
  std::cout << "Yes" << "\n";
  return 0;
}