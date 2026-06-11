#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cassert>
#include <bitset>

//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

//std::cout << std::fixed << std::setprecision(10)
//std::ios::sync_with_stdio(false);
constexpr long long MOD = 1000000007;

int dx[] = { 0, 1, 0, -1};
int dy[] = {-1, 0, 1,  0};

int main()
{
  long long k, q;
  std::cin >> k >> q;
  std::vector<long long> d1(k);
  for(auto& val: d1)
    std::cin >> val;
  while(q--)
  {
    int n, x, m;
    std::cin >> n >> x >> m;
    auto d = d1;
    for(auto& val: d)
      val %= m;
    long long ans = n - 1;
    ans -= std::count(d.begin(), d.end(), 0LL) * ((n - 1) / k);
    for(int i = 0; i < n-1-((n-1)/k)*k; ++i)
      if(d[i] % m == 0) ans--;
    long long sum = std::accumulate(d.begin(), d.end(), 0LL) * ((n - 1) / k) + x;
    for(int i = 0; i < n-1-((n-1)/k)*k; ++i)
      sum += d[i];
    ans -= sum/m - x/m;
    std::cout << ans << std::endl;
  }
  return 0;
}

