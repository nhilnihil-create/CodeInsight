#include<iostream>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  int N, L; std::cin >> N >> L;
  int sum = N*(L-1) + N*(N+1)/2;
  int i = std::min(N, std::max(1-L, 1));
  fin(sum - (L+i-1));
  return 0;
}
