#include <iostream>

int main()
{
  int A, B, C;
  std::cin >> A >> B >> C;
  if (A-B >= C) std::cout << 0 << std::endl;
  else std::cout << C - A + B << std::endl;
  return 0;
}