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

int N, M, Q;
struct X
{
  int a, b, c, d;
};
int dfs(int i, int n, std::vector<int>& A, const std::vector<X>& x)
{
  if(i == N)
  {
    int ans = 0;
    for(auto& val: x)
    {
      if(A[val.b-1] - A[val.a-1] == val.c)
        ans += val.d;
    }
    return ans;
  }

  int ans = 0;
  for(int m = n; m <= M; ++m)
  {
    A[i] = m;
    ans = std::max(ans, dfs(i + 1, m, A, x));
  }
  return ans;
}

int main()
{
  std::cin >> N >> M >> Q;
  std::vector<X> vec(Q);
  std::vector<int> A(N);
  for(auto& val: vec)
    std::cin >> val.a >> val.b >> val.c >> val.d;
  std::cout << dfs(0, 1, A, vec) << std::endl;
  return 0;
}

