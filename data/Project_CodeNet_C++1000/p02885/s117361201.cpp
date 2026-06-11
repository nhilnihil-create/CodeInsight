#include <iostream>

int main()
{
  int A, B;
  std::cin >> A >> B;
  std::cout << std::max(A - 2*B, 0) << std::endl;
  return 0;
}