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
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for(auto& val: A)
    std::cin >> val;
  std::unordered_map<int, int> m;
  long long ans = 0;
  for(int i = 0; i < A.size(); ++i)
  {
    auto it = m.find(i - A[i]);
    if(it != m.end())
    {
      ans += it->second;
    }
    m[i + A[i]]++;
  }
  std::cout << ans << std::endl;
  return 0;
}

