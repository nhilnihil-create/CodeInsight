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
  std::string S;
  std::cin >> N >> S;
  std::vector<std::array<int, 3>> memo(N);
  memo.back()[0] = 0;
  memo.back()[1] = 0;
  memo.back()[2] = 0;
  auto toIndex = [](char c)
  {
    if(c == 'R')
      return 0;
    else if (c == 'G')
      return 1;
    else
      return 2;
  };
  for(int i = N - 2; 0 <= i; --i)
  {
    memo[i] = memo[i + 1];
    ++memo[i][toIndex(S[i + 1])];
  }
  long long ans = 0;
  for(int i = 0; i < N; ++i)
  {
    for(int j = i + 1; j < N; ++j)
    {
      char c1 = S[i], c2 = S[j];
      if(c1 != c2)
      {
        int inc = 0;
        char c3 = 0;
        if(c1 != 'R' && c2 != 'R')
        {
          inc = memo[j][0];
          c3 = 'R';
        }
        else if(c1 != 'G' && c2 != 'G')
        {
          inc = memo[j][1];
          c3 = 'G';
        }
        else
        {
          inc = memo[j][2];
          c3 = 'B';
        }
        int d = j - i;
        if(j + d < N && c3 == S[j + d])
          --inc;
        ans += inc;
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}

