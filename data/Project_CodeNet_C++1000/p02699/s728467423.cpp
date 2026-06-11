#include <iostream>

int main()
{
  int S, W;
  std::cin >> S >> W;
  if (S > W) std::cout << "safe" << std::endl;
  else std::cout << "unsafe" << std::endl;
  return 0;
}