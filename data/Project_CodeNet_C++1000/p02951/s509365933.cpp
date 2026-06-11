#include<iostream>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  int A, B, C; std::cin >> A >> B >> C;
  fin(std::max(B+C-A, 0));
  return 0;
}
