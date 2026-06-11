#include<iostream>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  int X, A; std::cin >> X >> A;
  if(X < A) fin(0);
  fin(10);
  return 0;
}
