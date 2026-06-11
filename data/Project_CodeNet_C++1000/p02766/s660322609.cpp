#include <iostream>

int main()
{
  int N, K;
  std::cin >> N >> K;
  int res = 0;
  while (N>0) {
    N /= K; res++;
  }
  std::cout << res << std::endl;
  return 0;
}