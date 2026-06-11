#include <iostream>

int N, X, T;

int main() {
  std::cin >> N >> X >> T;
  std::cout << (N + X - 1) / X * T << "\n";

  return 0;
}
