#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  N %= 1000;
  std::cout << (1000-N)%1000 << std::endl;
  return 0;
}
