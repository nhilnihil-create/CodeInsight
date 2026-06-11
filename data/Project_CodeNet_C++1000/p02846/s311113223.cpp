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

using namespace std;
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
#define MEM_SIZE 10000
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
//SOLVE

template< typename T >
using Matrix = vector< vector< T > >;


void solve(void)
{
  int T1,T2;cin>>T1>>T2;
  int A1,A2; cin>>A1; cin>>A2;
  int B1,B2; cin>>B1; cin>>B2;
  if(A1 > B1)
  {
    swap(A1,B1);
    swap(A2,B2);
  }
  if(T1*A1 + T2*A2 == T1*B1 + T2*B2)
  {
    cout<<"infinity"<<endl;
    return;
  }
  if(T1*A1 + T2*A2 < T1*B1 + T2*B2)
  {
    cout<<0<<endl;
    return;
  }


  int D1 = T1*B1 - T1*A1;
  int UP = T1*A1 + T2*A2 - T1*B1 - T2*B2;
  // DEBUG(D1,UP,D1/UP);
  cout<<D1/UP*2 +(D1%UP >0)<<endl;


  
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
