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

ll N, K;
ll dp[310][310];
ll H[310];

int main()
{
  std::cin >> N >> K;

  rep( i, N )
    std::cin >> H[i];

  ll M = N-K;

  rep( i, N ) rep( j, M+1 ) {
    if( !j )
      dp[i][0] = H[i];
    else
      dp[i][j] = INF;
  }

  rep( i, N ) repi( j, 1, M ) {
    rep( k, i )
      chmin( dp[i][j], dp[k][j-1]+std::max(0ll, H[i]-H[k]) );
  }

  ll ans = INF;

  rep( i, N )
    chmin( ans, dp[i][M-1] );

  std::cout << ans << std::endl;

  return 0;
}