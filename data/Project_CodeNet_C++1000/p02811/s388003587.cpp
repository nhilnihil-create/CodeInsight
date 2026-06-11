#include <iostream>

int main()
{
  int K, X;
  std::cin >> K >> X;

  bool over_X = (X <= 500 * K);

  std::cout << (over_X ? "Yes" : "No") << std::endl;

  return 0;
}
