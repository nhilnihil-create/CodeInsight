#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>

typedef long double ld;
typedef long long ll;

void print(){ std::cout << std::endl; }
template<typename H> void print(H&& head){ std::cout << head << std::endl; }
template<typename H, typename... T> void print(H&& head, T&&... tail){
  std::cout << head << " ", print(std::forward<T>(tail)...);
}

void solve()
{
  ll arr[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

  ll K;
  std::cin >> K;

  print(arr[K-1]);

  return;
}

int main()
{
  solve();
  return 0;
}

