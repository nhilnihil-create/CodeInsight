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
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

void print(){ std::cout << std::endl; }
template<typename H> void print(H&& head){ std::cout << head << std::endl; }
template<typename H, typename... T> void print(H&& head, T&&... tail){
  std::cout << head << " ", print(std::forward<T>(tail)...);
}

void solve()
{
  ll M1, D1, M2, D2;
  std::cin >> M1 >> D1 >> M2 >> D2;

  if (D2 == 1) print(1);
  else print(0);

  return;
}

int main()
{
  solve();
  return 0;
}

