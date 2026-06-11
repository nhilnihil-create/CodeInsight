#include <iostream>

int main()
{
  int N;
  std::cin >> N;

  int n_odd = N/2 + N%2;

  std::cout <<std::fixed << n_odd / double(N) << std::endl;
  return 0;
}
