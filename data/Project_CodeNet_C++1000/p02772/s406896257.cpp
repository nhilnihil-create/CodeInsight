#include <iostream>

int main() {
  int n; std::cin >> n;
  bool ok = true;
  while (n--) {
    int a; std::cin >> a;
    if (a%2 == 0 && a%3 != 0 && a%5 != 0) ok = false;
  }
  if (ok) std::cout << "APPROVED" << std::endl;
  else std::cout << "DENIED" << std::endl;
  
  return 0;
}