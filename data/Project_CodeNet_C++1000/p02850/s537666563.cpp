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

void DFS(int V,int P,int C,int PC,vector<vector<int> > & GRAPH,vector<int> &color,map<pair<int,int> ,int> & mp)
{
  if(PC != -1)//initial
  color[mp[make_pair(P,V)]] = C;
  int nC = 1;
  for (auto &&i : GRAPH[V])
  {
    if(i == P)continue;
    while(nC == C)nC++;

    DFS(i,V,nC,C,GRAPH,color,mp);
    nC++;
  }
  return;
}
void solve(void)
{
  int N;cin>>N;
  vector<vector<int> > GRAPH(N);
  map<pair<int,int> ,int>mp;
  for (int i = 0; i < N-1; i++)
  {
    int A,B;
    cin>>A>>B;
    A--;B--;
    GRAPH[A].push_back(B);
    GRAPH[B].push_back(A);
    mp[make_pair(A,B)] = i;
    mp[make_pair(B,A)] = i;
  }
  vector<int> color(N,-1);
  DFS(0,-1,0,-1,GRAPH,color,mp);
  set<int> SET;
  for (int i = 0; i < N-1; i++)
  {
    SET.insert(color[i]);
  }
  cout<<SET.size()<<endl;
  
  for (int i = 0; i < N-1; i++)
  {
    cout<<color[i]<<endl;
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
