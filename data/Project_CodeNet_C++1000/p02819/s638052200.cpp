#include <iostream>
#include <cmath>

bool isPrime(int n)
{
  int m = (int)std::sqrt((double)n);
  for (int p=2; p<=m; p++) {
    if (n%p==0) return false;
  }
  return true;
}

int main()
{
  int N;
  std::cin >> N;
  for (; !isPrime(N); N++);
  std::cout << N << std::endl;
  return 0;
}