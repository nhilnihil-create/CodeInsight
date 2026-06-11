#include <iostream>
#include <cmath>

int main() {

  int N;
  int X;
  int T;

  std::cin >> N;
  std::cin >> X;
  std::cin >> T;

  std::cout << (int) (std::ceil((double) N / X) * T) << std::endl;

  return 0;

}
