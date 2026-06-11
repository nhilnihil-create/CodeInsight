#include <iostream>
#include <algorithm>

int main()
{
  int N, K;
  std::cin >> N >> K;
  int* p = new int[N];
  for (int i=0; i<N; i++) std::cin >> p[i];
  std::sort(p, p+N);
  int res = 0;
  for (int i=0; i<K; i++) res += p[i];
  std::cout << res << std::endl;
  delete[] p;
  return 0;
}
