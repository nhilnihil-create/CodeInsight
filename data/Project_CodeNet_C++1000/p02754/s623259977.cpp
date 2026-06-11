#include <iostream>

int main()
{
  long long N, A, B;
  std::cin >> N >> A >> B;
  std::cout << (N/(A+B))*A + std::min(A, N%(A+B)) << std::endl;
  return 0;
}
