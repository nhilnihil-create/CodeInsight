#include <iostream>

int main()
{
  int X, Y;
  std::cin >> X >> Y;
  if (Y%2==1) std::cout << "No" << std::endl;
  else {
    if (2*X - Y/2 >= 0 && Y/2 - X >= 0) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
  }
  return 0;
}
