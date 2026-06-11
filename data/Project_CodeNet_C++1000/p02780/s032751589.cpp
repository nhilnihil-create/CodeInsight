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
  int N, K;
  std::cin >> N >> K;
  std::vector<int> p(N);
  for(auto& val: p)
    std::cin >> val;
  double ans = 0.0;
  auto expect = [](int n)
  {
    return ((double)(((n + 1)*n)/2)) / n;
  };
  for(int i = 0; i < K; ++i)
  {
    ans += expect(p[i]);
  }
  double tmp = ans;
  for(int i = K; i < N; ++i)
  {
    tmp -= expect(p[i - K]);
    tmp += expect(p[i]);
    ans = std::max(ans, tmp);
  }
  std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
  return 0;
}

