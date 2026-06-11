#include<iostream>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  int64_t a, b, c; std::cin >> a >> b >> c;
  int64_t k = c - (a+b);
  if(k < 0) fin("No");
  if(k*k > 4*a*b) fin("Yes");
  fin("No");
  return 0;
}
