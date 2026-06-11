#include<bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353 
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


void solve(void)
{
  int N,K,C; cin>>N; cin>>K;cin>>C;
  string str;cin>>str;
  vector<int> L(K,0);
  vector<int> R(K,0);
  int cnt = 0;
  int dcnt = INF;
  int d = 0;
  for (auto &&s : str)
  {
    if(s =='o' && dcnt >= C)
    {
      L[cnt] = d;
      dcnt = -1;
      cnt++;
    }
    if(cnt == K)break;
    d++;
    dcnt++;
  }
  reverse(ALL(str));
  cnt = 0;
  dcnt = INF;
  d = 0;
  for (auto &&s : str)
  {
    if(s =='o' && dcnt >= C)
    {
      R[cnt] = N -1 - d;
      dcnt = -1;
      cnt++;
    }
    if(cnt == K)break;
    d++;
    dcnt++;
  }
  reverse(ALL(R));
  // DEBUG(L,R);
  for (int i = 0; i < K; i++)
  {
    if(L[i] == R[i])
    {
      cout<<R[i] + 1<<endl;
    }
  }
  
  
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
