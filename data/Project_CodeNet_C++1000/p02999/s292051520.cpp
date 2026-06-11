#include <iostream>

int main()
{
  int X, A;
  std::cin >> X >> A;

  int ret = 0;
  if(A <= X) {
    ret = 10;
  }

  std::cout << ret << std::endl;
  return 0;
}
