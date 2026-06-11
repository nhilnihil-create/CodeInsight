#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  int res = (N%2==1) ? N/2 + 1 : N/2;
  std::cout << res << std::endl;
  return 0;
}