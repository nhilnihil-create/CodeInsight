
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <sstream>
#include<limits.h>
#include<float.h>
#include<list>
#include <array>
#include <complex>
#include<stdio.h>
#include<string.h>
#include <bitset>
// #include<assert.h>
#include<random>
using namespace std;
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
// #define MOD 1000000007
#define MOD 998244353 
#define MEM_SIZE 100010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

void DynamicProgramming(int x,vector<vector<int> > & dp)
{


  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      int t = i*100 + j*10 + x;
      int tt = i*10 + j;
      dp[2][t] |= dp[1][tt];
    }
  }

  for (int i = 0; i < 10; i++)
  {
    int t =i*10 + x;
    dp[1][t] |= dp[0][i];
  }

  dp[0][x] = 1;
  
  return ;
}

void solve(void)
{
  int n;cin>>n;
  vector<int> vec (n,0);
  for (int i = 0; i < n; i++)
  {
    char x;cin>>x;
    vec[i] = x - '0';
  }
  vector<vector<int> > dp (3,vector<int>(1000,0));
  for (int i = 0; i < n; i++)
  {
    int x = vec[i];
    DynamicProgramming(x,dp);
  }
  int res = 0;
  for (int i = 0; i < 1000; i++)
  {
    res += dp[2][i];
  }
  // DEBUG(dp);
  cout<<res<<endl;
  
  


  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
