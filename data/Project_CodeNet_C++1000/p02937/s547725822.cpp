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


void solve(void)
{
  string str,ref;
  cin>>str>>ref;
  map<char,int> pos;
  int N = str.size();
  vector<int> next (26,-1);
  vector<vector<int> > mat (26,vector<int>(N,-1));
  
  for (int i = N-1; i >= 0; i--) 
  {
    char c = str[i];
    for (int j = 0; j < 26; j++)
    {
      mat[j][i] = next[j];
    }
    next[(int)(c-'a')] = i;
  }
  for (int i = N-1; i >= 0; i--) 
  {
    char c = str[i];
    for (int j = 0; j < 26; j++)
    {
      if(mat[j][i] == -1)
      mat[j][i] = next[j];
    }
    next[(int)(c-'a')] = i;
    // DEBUG(next);
  }
  // DEBUG(next);
  // DEBUG(mat);
  int index = 0;
  int lcnt = 0;
  int flg = 0;
  for (int i = 0; i < ref.size(); i++)
  {
    int ni = mat[(int)(ref[i]-'a')][index];
    if(i == 0)
    {
      ni = next[(int)(ref[i]-'a')];
      if(ni == -1)
      {
        cout<<-1<<endl;
        return;
      }
      index = ni;
      continue;
    }
    if(ni == -1)
    {
      cout<<-1<<endl;
      return;
    }
    if(ni <= index && i != 0)lcnt++;
    index = ni;
    // DEBUG(index,ni,"\n");
  }

  cout<<lcnt*N + index + 1 - flg<<endl;
  

  
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
