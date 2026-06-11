#include <iostream>

int main()
{
  int K, A, B;
  std::cin >> K;
  std::cin >> A >> B;
  if (A/K < B/K) std::cout << "OK" << std::endl;
  else if (A%K==0) std::cout << "OK" << std::endl;
  else std::cout << "NG" << std::endl;
  return 0;
}
