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

int solve(int K)
{
  if(K < 10)
  {
    std::cout << K << std::endl;
    return 0;
  }
  std::vector<std::vector<long long>> prev(10);
  for(int i = 0; i < prev.size(); ++i)
    prev[i].push_back(i);
  int cnt = 9;
  long long pow = 10;
  while(true)
  {
    std::vector<std::vector<long long>> nexts(10);
    {
      std::vector<long long> next;
      next.reserve(prev[0].size() + prev[1].size());
      for(auto val: prev[0])
        next.push_back(val);
      for(auto val: prev[1])
        next.push_back(val);
      nexts[0] = std::move(next);
    }
    for(int i = 1; i < 9; ++i)
    {
      std::vector<long long> next;
      next.reserve(prev[i - 1].size() + prev[i].size() + prev[i + 1].size());
      for(auto val: prev[i - 1])
      {
        next.push_back(pow * i + val);
        ++cnt;
        if(cnt == K)
        {
          std::cout << next.back() << std::endl;
          return 0;
        }
      }
      for(auto val: prev[i])
      {
        next.push_back(pow * i + val);
        ++cnt;
        if(cnt == K)
        {
          std::cout << next.back() << std::endl;
          return 0;
        }
      }
      for(auto val: prev[i + 1])
      {
        next.push_back(pow * i + val);
        ++cnt;
        if(cnt == K)
        {
          std::cout << next.back() << std::endl;
          return 0;
        }
      }
      nexts[i] = std::move(next);
    }
    {
      std::vector<long long> next;
      next.reserve(prev[8].size() + prev[9].size());
      for(auto& val: prev[8])
      {
        next.push_back(pow * 9  + val);
        ++cnt;
        if(cnt == K)
        {
          std::cout << next.back() << std::endl;
          return 0;
        }
      }
      for(auto& val: prev[9])
      {
        next.push_back(pow * 9 + val);
        ++cnt;
        if(cnt == K)
        {
          std::cout << next.back() << std::endl;
          return 0;
        }
      }
      nexts.back() = std::move(next);
    }
    prev.swap(nexts);
    pow *= 10;
  }
  return 0;
}

int main()
{
  int K;
  std::cin >> K;
  solve(K);
  return 0;
}

