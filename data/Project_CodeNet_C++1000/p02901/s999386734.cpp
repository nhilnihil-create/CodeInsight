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

ll N, M;
ll a[1010], bit[1010];
ll dp[1010][(1<<12)+10];

int main()
{
  std::cin >> N >> M;

  rep( i, M ) {
    ll b;
    std::cin >> a[i] >> b;

    rep( j, b ) {
      ll c;
      std::cin >> c;
      --c;

      bit[i] |= 1<<c;
    }
  }

  rep( i, M+1 ) rep( j, 1<<N )
    dp[i][j] = INF;

  dp[0][0] = 0;

  rep( i, M ) rep( j, 1<<N ) {
    chmin( dp[i+1][j], dp[i][j] );
    chmin( dp[i+1][j|bit[i]], dp[i][j]+a[i] );
  }

  std::cout << (dp[M][(1<<N)-1]!=INF ? dp[M][(1<<N)-1] : -1) << std::endl;

  return 0;
}