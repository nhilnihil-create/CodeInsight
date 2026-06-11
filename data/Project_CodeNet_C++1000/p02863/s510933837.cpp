#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using ll = long long;
using P = std::pair<ll, ll>;

constexpr ll INF = 1ll<<60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

ll N, T;
ll A[3010], B[3010];
ll dp[3010][3010];
std::vector<P> ps;
ll right[3010];

int main()
{
  std::cin >> N >> T;
  
  rep( i, N ) {
    std::cin >> A[i] >> B[i];

    ps.emplace_back( A[i], B[i] );
  }

  std::sort(all(ps));

  rep( i, N )
    A[i] = ps[i].first, B[i] = ps[i].second;

  rep( i, N ) rep( j, T ) {
    chmax( dp[i+1][j], dp[i][j] );
    
    if( j-A[i] >= 0 )
      chmax( dp[i+1][j], dp[i][j-A[i]]+B[i] );
  }

  ll ans = 0;

  rep( i, N+1 )
    chmax( ans, dp[i][T-1]+B[i] );

  std::cout << ans << std::endl;

  return 0;
}