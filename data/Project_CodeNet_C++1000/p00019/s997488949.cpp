#include <iostream>

int main() {
  int n;

  std::cin >> n;

  long long int factorial = 1;
  while (n > 0)
    factorial *= n--;

  std::cout << factorial << std::endl;

  return 0;
}