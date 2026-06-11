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
  int N, K, S;
  std::cin >> N >> K >> S;
  if(S != 1000000000)
  {
    for(int i = 0; i < K; ++i)
    {
      std::cout << S << " ";
    }
    for(int i = K; i < N; ++i)
    {
      std::cout << S + 1 << " ";
    }
  }
  else
  {
    for(int i = 0; i < K; ++i)
    {
      std::cout << S << " ";
    }
    for(int i = K; i < N; ++i)
    {
      std::cout << 1 << " ";
    }
  }
  std::cout << std::endl;
  return 0;
}

