#include <iostream>

int main()
{
  int N, M;
  std::cin >> N >> M;
  int sum = 0;
  int A;
  for (int i=0; i<M; i++) {
    std::cin >> A;
    sum += A;
  }
  if (N-sum>=0) std::cout << N-sum << std::endl;
  else std::cout << -1 << std::endl;
  return 0;
}
  