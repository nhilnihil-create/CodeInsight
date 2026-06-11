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
  long long N, K;
  std::cin >> N >> K;
  long long ans = 0;
  for(long long k = K; k <= N + 1; ++k)
  {
    ans += (N - k + 1) * k + 1;
    ans %= MOD;
  }
  std::cout << ans << std::endl;
  return 0;
}

