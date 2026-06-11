
#include<bits/stdc++.h>
using namespace std;
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD1 998244353 
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


void DFS(int X,priority_queue<int, vector<int>, greater<int> >& q,int TH = 10000000000)
{
  if(X > TH)return;
  q.push(X);
  string str = to_string(X);
  int B = (int)(str.back() - '0');
  if(B != 0)DFS(stol(str + to_string(B-1)),q,TH);
  if(B != 9)DFS(stol(str + to_string(B+1)),q,TH);
  DFS(stol(str + to_string(B)),q,TH);
  return;
}
void solve(void)
{
  int K;cin>>K;
  priority_queue<int, vector<int>, greater<int> > q;
  for (int i = 1; i <= 9; i++)
  {
    DFS(i,q);
  }
  for (int i = 0; i < K-1; i++)
  {
    q.pop();
  }
  cout<<q.top()<<endl;  
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
