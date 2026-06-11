#include <cmath>
#include <iostream>
#include <vector>

int main() {
  uint32_t n = 0;
  std::cin >> n;
  std::cout << n << ":";

  uint32_t remain = n;
  while (remain % 2 == 0) {
    std::cout << " " << 2;
    remain /= 2;
  }

  for (size_t i = 3; i * i <= remain; i += 2) {
    while (remain % i == 0) {
      std::cout << " " << i;
      remain /= i;
    }
  }

  if (remain != 1) std::cout << " " << remain;
  std::cout << std::endl;

  return 0;
}
