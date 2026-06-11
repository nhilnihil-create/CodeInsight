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
string str;
int K;
cin>>str>>K;
vector<pair<char,int> > vp;
vp.emplace_back(str[0],1);
for (int i = 1; i < str.size(); i++)
{
  if(vp.back().first == str[i]) vp.back().second++;
  else vp.emplace_back(str[i],1);
}
if(vp.size() == 1)
{
  cout<<(K*vp[0].second)/2<<endl;
  return;
}
int ANS = 0,T = 0;
ANS += vp[0].second/2;
for (int i = 1; i+1 < vp.size(); i++)T += vp[i].second/2;
ANS += T*K;
// DEBUG(ANS);
ANS += vp.back().second/2;

if(vp[0].first == vp.back().first)
{
  ANS += (K-1)*((vp[0].second + vp.back().second)/2);
}
else
{
  ANS += (K-1)*(vp[0].second/2 + vp.back().second/2);
}
cout<<ANS<<endl;

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
