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

using namespace std;
#define i64  long long
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
#define MEM_SIZE 10000
#define DEBUG_OUT true
#define ALL(x) (x).begin(),(x).end()
// int DP[MEM_SIZE][MEM_SIZE] = {0};
// int GMEM[MEM_SIZE][MEM_SIZE] = {0};
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return;std::cout << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class X> void DEBUG(X d, T e){if(DEBUG_OUT == false)return;std::cout <<d<<" ";DEBUG(e);};
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

  // vector<vector<vector<int> > > DP =  vector<vector<vector<int> > >(100001,vector<vector<int> >(2,vector<int>(2,0)));
  vector<vector<int> > DP (100001,vector<int>(2,0));
void solve(void)
{
  string L;
  cin>>L;
  vector<int> n;
  for (int i = 0; i < L.size(); i++)
  {
    n.push_back(L[i] - '0');
  }
  int l = n.size();
    DP[0][0] = 1;
  for (int i = 0; i < l; i++)
  {
    // for (int j = 0; j < 2; j++)
    // {
    //   for (int k = 0; k < 2; k++)
    //   {
    //     for (int p = 0; p <= (j?1:n[i]); p++)//未満フラグが経って入れば9まで走査 未満フラグが経っていなければその数字の上限となりうる桁まで走査
    //     {
    //       DP[i+1][j||p<n[i]] += DP[i][j]*2;
    //       DP[i+1][j||p<n[i]] %= MOD;
    //     }
        
    //   }
      
    // }
    DP [i+1][1] += (DP[i][1]*3)%MOD;
    DP[i+1][1] %= MOD;

    if(n[i] == 1)
    {
      DP[i+1][1] += DP[i][0];
      DP[i+1][0] += (DP[i][0]*2%MOD);
      DP[i+1][1] %= MOD;
      DP[i+1][0] %= MOD;


    }
    else
    {
      DP[i+1][0] += DP[i][0];
      DP[i+1][0] %= MOD;
    }
    DP[i+1][0] %=MOD;
    DP[i+1][1] %=MOD;
    
  }
  // DEBUG(DP[0]);
  cout<<(DP[l][0] + DP[l][1])%MOD<<endl;
  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(9);
  solve();

  return 0;
}
