#include <iostream>

int main(int argc, char *argv[]) {
  int m1, d1, m2;
  std::cin >> m1 >> d1 >> m2;
  std::cout << (m1 != m2 ? 1 : 0) << std::endl;
}
