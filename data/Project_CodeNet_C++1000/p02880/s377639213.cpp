#include <iostream>

int main() {
  int n; std::cin >> n;
  bool ok = false;
  for (int i = 1; i <= 9; ++i) {
    if (n%i != 0) continue;
    int a = n/i;
    if (1 <= a && a <= 9) ok = true;
  }
  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  return 0;
}