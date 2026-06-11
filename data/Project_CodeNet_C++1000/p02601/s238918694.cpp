#include <iostream>

int check(int x, int& y) {
  int times = 0;
  while (y <= x) {
    ++times;
    y *= 2;
  }
  return times;
}

int main() {
  int a, b, c, k;
  std::cin >> a >> b >> c >> k;
  int times = 0;
  times += check(a, b);
  times += check(b, c);
  if (times <= k) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}