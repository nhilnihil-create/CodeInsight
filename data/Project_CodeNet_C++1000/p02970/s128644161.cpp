#include<iostream>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  int N, D; std::cin >> N >> D;
  int k = D*2+1;
  fin((N+k-1)/k);
  return 0;
}
