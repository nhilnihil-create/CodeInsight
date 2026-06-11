#include <iostream>

int main()
{
  int A, B, C, K;
  std::cin >> A >> B >> C >> K;
  int res;
  if (A >= K) res = K;
  else if (A + B >= K) res = A;
  else res = 2*A + B - K;
  std::cout << res << std::endl;
  return 0;
}