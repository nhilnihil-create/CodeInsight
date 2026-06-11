#include <iostream>

int main()
{
  int H, N;
  std::cin >> H >> N;
  int sum = 0;
  for (int i=0; i<N; i++) {
    int A;
    std::cin >> A;
    sum += A;
  }
  if (sum >= H) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}