#include <iostream>

int main() {
  for (int i = 1; i <= 5; ++i) {
    int x;  std::cin >> x;
    if (x == 0)
      std::cout << i << "\n";
  }

  return 0;
}
