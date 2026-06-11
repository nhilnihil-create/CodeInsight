#include <iostream>

int main() {
  int k, a, b; std::cin >> k >> a >> b;
  bool ok = false;
  for (int i = a; i <= b; ++i) {
    if (i%k == 0) ok = true; 
  }
  if (ok) std::cout << "OK" << std::endl;
  else std::cout << "NG" << std::endl;
  
  return 0;
}