#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  int t_c, a_c;
  t_c = (c + b - 1) / b;
  a_c = (a + d - 1) / d;
  if (t_c <= a_c) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  return 0;
}
