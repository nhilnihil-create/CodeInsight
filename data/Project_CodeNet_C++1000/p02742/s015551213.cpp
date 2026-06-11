#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>

typedef long double ld;
typedef long long ll;

void print(){ std::cout << std::endl; }
template<typename H> void print(H&& head){ std::cout << head << std::endl; }
template<typename H, typename... T> void print(H&& head, T&&... tail){
  std::cout << head << " ", print(std::forward<T>(tail)...);
}

int main()
{
  ll H, W;
  std::cin >> H >> W;

  if (H == 1 || W == 1) {
    print(1);
    return 0;
  }

  ll ans = (H * W + 1) / 2;

  print(ans);

  return 0;
}

