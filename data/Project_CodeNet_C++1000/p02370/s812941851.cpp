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
#include<list>
#include <array>
#include <complex>
using namespace std;
#define i64  long long
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807
#define INF I64_MAX
#define MOD 1000000007
#define MEM_SIZE = 1e5+5;

template<typename T> void DEBUG(T e){std::cout << e << std::endl;}
template<class T> void DEBUG(string str, T e){std::cout <<str << ">>" << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ DEBUG(v); } }
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}




//-----CODE------//
void topological_sort_BFS(vector<vector<int> >&GRAPH,vector<bool> & V,vector<int>& DEG, int NODE,vector<int>& sorted)
{
  queue<int> q;
  q.push(NODE);
  V[NODE] = true;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    sorted.push_back(u);
    for (int i = 0; i < GRAPH[u].size(); i++)
    {
      int v = GRAPH[u][i];
      DEG[v]--;
      if((DEG[v] == 0)&&(V[v] == false))
      {
        V[v] = true;
        q.push(v);
      }
    }
    
  }
}

vector<int> topological_sort(vector<vector<int> >&GRAPH)
{
  int N = GRAPH.size();
  vector<bool> V(N,false);
  vector<int> DEG(N,0);
  vector<int> sorted;
  for (int i = 0; i < N ; i++)
  {
    for (int s = 0; s < GRAPH[i].size(); s++)
    {
      DEG[GRAPH[i][s]]++;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if((DEG[i] == 0) && (V[i] == false))
    {
      topological_sort_BFS(GRAPH,V,DEG,i,sorted);
    }
  }
  
  return sorted;
}
void solve(void)
{
  int N;
  int M;
  cin>>N>>M;;
  vector<vector<int> > GRAPH(N);
  for (int i = 0; i < M; i++)
  {
    int A,B;
    cin>>A>>B;
    GRAPH[A].push_back(B);
  }
  vector<bool>V(N,false);
  vector<int> sorted;
  sorted = topological_sort(GRAPH);
  for (int i = 0; i < N; i++)
  {
    cout<<sorted[i]<<endl;
  }
  cout<<endl;
  
  
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
