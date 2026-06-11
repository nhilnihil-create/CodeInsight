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
void solve(void)
{
  int N,K;
  cin>>N>>K;
  if((N-1)*(N-2)/2 <K)
  {
    cout<<-1<<endl;
    return;
  }
  int X = (N-1)*(N-2)/2 - K;
  int M =N-1 + X;
  cout<<M<<endl;;
  for (int i = 0; i < N-1; i++)
  {
    cout<<1 <<" "<<i+2<<endl;
  }
  vector<pair<int,int> > data;
  for (int i = 2; i < N; i++)
  {
    for (int j = i+1; j < N+1; j++)
    {
      pair<int,int> p;
      p.first = i; p.second = j;
      data.push_back(p);
    }
    
  }
  for (int i = 0; i < X; i++)
  {
    cout<<data[i].first <<" "<<data[i].second<<endl;
  }
  
  
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
