#include <iostream>

using ll = long long;
template<class H> void print(H head) {std::cout << head << std::endl;}

int main()
{
  ll A, B, C;
  std::cin >> A >> B >> C;

  ll ans = std::max(0LL, C - A + B);
  print(ans);

  return 0;
}
