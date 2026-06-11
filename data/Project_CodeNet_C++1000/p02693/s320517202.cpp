#include <iostream>

int main() {
  int k, a, b;
  std::cin >> k >> a >> b;
  for (int i = a; i <=b; ++i) {
    if (i % k == 0) {
      std::cout << "OK";
      return 0;
    }
  }
  std::cout << "NG";
}