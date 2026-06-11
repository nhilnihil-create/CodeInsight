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
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
#define MEM_SIZE 10000
#define DEBUG_OUT true
#define ALL(x) (x).begin(),(x).end()

template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }



void solve(void)
{
  int N,M;
  cin>>N>>M;
  vector<vector<int> >  GRAPH(3*N);
  for (int i = 0; i < M; i++)
  {
    int A,B;
    cin>>A>>B;
    A--;B--;
    GRAPH[A].emplace_back(B + N);
    GRAPH[N + A].emplace_back(B + 2*N);
    GRAPH[2*N + A].emplace_back(B);
    // GRAPH[B].emplace_back(A);
  }
  int S,T;cin>>S>>T;S--;T--;
  queue<int> q;
  q.push(S);
  vector<int> path (3*N,INF);
  path[S] = 0;
  // DEBUG(GRAPH2);
  while(!q.empty())
  {
    int V = q.front();
    q.pop();

    for (int i = 0; i < GRAPH[V].size(); i++)
    {
      int nV = GRAPH[V][i];
      // DEBUG(GRAPH2[V].size(),"\n");
      if(path[nV] == INF)
      {
        path[nV] = path[V]+1;
        q.push(nV);
      }
    }
    // DEBUG(path);
  }
    // DEBUG(path,char(10));
    if (path[T] == INF)
    {
      cout << -1 << endl;
      return;
    }

  cout<<path[T]/3<<endl;

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
