#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
 
using ll = long long;
using P = std::pair<long double, ll>;
 
#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << #i <<" "<<i<< std::endl
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;


 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n,m;
  std::cin>>n>>m;

  std::vector<ll> s(n),t(m);
  rep(i,0,n)std::cin>>s[i];
  rep(i,0,m)std::cin>>t[i];

  std::vector<std::vector<ll>> sum(n+1,std::vector<ll>(m+1,0));

  rep(i,0,m+1)sum[0][i]=1;
  rep(i,0,n+1)sum[i][0]=1;

  rep(i,1,n+1){
    ll temp=0;
    rep(j,1,m+1){
      if(s[i-1]==t[j-1])temp=(temp+sum[i-1][j-1])%MOD;
      sum[i][j]=(sum[i-1][j]+temp)%MOD;
    }
  }

  std::cout<<sum[n][m];

  return 0;
}



