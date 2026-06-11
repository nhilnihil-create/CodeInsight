#include <iostream>

int main(void)
{
  int r;
  std::cin >> r;
  if(!(r > 100 && r <= 0)) std::cout << r * r << std::endl;
  return 0;
}
