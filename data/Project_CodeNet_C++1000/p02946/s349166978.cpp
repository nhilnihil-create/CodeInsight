#include <iostream>

int main() {
  int k, x;
  std::cin >> k >> x;
  for (int i = x - k + 1; i <= x + k - 1; ++i)
    std::cout << i << " ";
}
