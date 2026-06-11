#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  if (N%2==0) std::cout << 0.5 << std::endl;
  else std::cout << (double)(N/2 + 1) / N << std::endl;
  return 0;
}
