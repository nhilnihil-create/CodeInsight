#include <iostream>

int main()
{
  int H, A;
  std::cin >> H >> A;
  if (H%A==0) std::cout << H/A << std::endl;
  else std::cout << H/A + 1 << std::endl;
  return 0;
}
