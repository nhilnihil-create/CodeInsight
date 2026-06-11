
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
#define MOD 1000000007
// #define MOD1 998244353 
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

template< typename T >
struct edge {
  int src, to;
  T cost;
 
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
 
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
 
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
 
  operator int() const { return to; }
};
 
template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
 
 
vector<int> dijkstra(WeightedGraph<int> &G,int s)
{ 
  
  vector<int> path(G.size(),I64_MAX);
  path[s] = 0;
  priority_queue <pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > que;
 
  que.emplace(path[s],s);
 
  while(!que.empty())
  {
    int cost;
    int idx;
    tie(cost,idx) = que.top();
    que.pop();
 
    if(path[idx] < cost) continue;
    for (auto &e: G[idx])
    {
      int next_cost = cost + e.cost;
      if(path[e.to] <= next_cost) continue;
      path[e.to] = next_cost;
      que.emplace(path[e.to],e.to);
    }
  }
 
  return path;
}
 


void solve(void)
{
  int N,M;
  cin>>N>>M;
  WeightedGraph<int> WG(3*N);
  for (int i = 0; i < M; i++)
  {
    int A,B,C;
    cin>>A>>B;
    A--;B--;
    C =  1;
    WG[A].emplace_back(A,B+N,C);
    WG[A+N].emplace_back(A,B+2*N,C);
    WG[A+2*N].emplace_back(A,B,C);
  }
  int S,T;cin>>S>>T;S--;T--;
  auto path = dijkstra(WG,S);
  if(path[T] >= INF)
  {
    cout<<-1<<endl;
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
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
