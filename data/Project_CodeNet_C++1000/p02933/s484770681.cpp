#include <iostream>
#include <string>

using ll = long long;

template<class H, class T> H maximum(H head, T tail) { return std::max(head, tail); }
template<class H, class... T> H maximum(H head, T... tail) { return std::max(head, maximum(tail...)); }

template<class H> void print(H head) {std::cout << head << std::endl;}

int main()
{
  ll A;
  std::string s;
  std::cin >> A >> s;

  if (A < 3200) s = "red";
  print(s);

  return 0;
}
