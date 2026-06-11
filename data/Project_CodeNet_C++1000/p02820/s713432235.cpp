#include <cstdio>
#include <cstdlib>
#include <cmath>
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
#include <tuple>
#include <vector>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define endl '\n'
#define debug(x) std::cerr << #x << " = " << (x) << endl;

using ll = long long;
using Pr = std::pair<ll, ll>;

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
ll R, S, P;
std::string T;
std::string vs[100010];

// 0: r, 1: s, 2: p
ll win( char ch, ll l ) {
  if( ch == 'r' ) {
    return l == 2 ? P : 0;
  } else if( ch == 's' ) {
    return l == 0 ? R : 0;
  } else {
    return l == 1 ? S : 0;
  }
}

int main() {
  std::cin >> N >> K >> R >> S >> P >> T;

  rep( i, N ) {
    vs[i%K] += T[i];
  }

  ll ans = 0;

  rep( i, K ) {
    std::vector<std::vector<ll>> dp( vs[i].size()+10, std::vector<ll>( 3, 0 ) );

    rep( j, vs[i].size() ) rep( k, 3 ) rep( l, 3 ) {
      if( l == k )
        continue;
      
      chmax( dp[j+1][l], dp[j][k]+(win(vs[i][j], l) ? win(vs[i][j], l) : 0) );
    }

    ll ma = 0;

    rep( k, 3 )
      chmax( ma, dp[vs[i].size()][k] );
    
    ans += ma;
  }

  std::cout << ans << endl;

  return 0;
}