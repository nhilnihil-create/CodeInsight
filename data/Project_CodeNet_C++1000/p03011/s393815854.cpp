#include<iostream>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int P, Q, R; std::cin >> P >> Q >> R;
  fin(P+Q+R - std::max(P, std::max(Q, R)));
  return 0;
}
