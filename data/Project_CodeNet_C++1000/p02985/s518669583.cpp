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

// int DP[MEM_SIZE][MEM_SIZE] = {0};
// int GMEM[MEM_SIZE][MEM_SIZE] = {0};
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }


void DFS(int V,vector<vector<int> >&GRAPH,vector<int>& used,int from,int K,int & res)
{
  // if(used[V] == 1)return;
  used[V] = 1;
  // DEBUG(V);
  int COUNT = K- 2;
  if(from == -1)COUNT = K -1;
  for (int i = 0; i < GRAPH[V].size(); i++)
  {
    if(used[GRAPH[V][i]] == 0)
    {
      DFS(GRAPH[V][i],GRAPH,used,V,K,res);
      res *= COUNT;
      res %= MOD;
      COUNT--;
      // DEBUG(ANS*K%MOD);
    }
  }
  return;
}

void GRAPH_DFS(void)
{
  int N,K;
  cin>>N>>K;
  vector<vector<int> > GRAPH(N);
  for (int i = 0; i < N-1; i++)
  {
    int A,B;
    cin>>A>>B;
    A--;B--;
    GRAPH[A].push_back(B);
    GRAPH[B].push_back(A);
  }
  vector<int> used(N,0);
  int ANS = 1;
  DFS(0,GRAPH,used,-1,K,ANS);
  cout<<ANS*K%MOD<<endl;
  return;
}
void solve(void)
{
  GRAPH_DFS();
  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(15);
  solve();

  return 0;
}
