#include <cstdio>
#include <cstdlib>
#include <cstring>
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

ll N;
ll A[1010][1010];
std::vector<ll> G[1000010];

ll comp( ll i, ll j ) {
  if( i > j )
    std::swap( i, j );

  return i*1000+j;
}

ll deg[1000010], top[1000010];

int main()
{
  std::cin >> N;

  rep( i, N ) {
    rep( j, N-1 )
      std::cin >> A[i][j], --A[i][j];

    rep( j, N-2 ) {
      ll from = comp( i, A[i][j] );
      ll to = comp( i, A[i][j+1] );
      G[from].emplace_back( to );
      ++deg[to];
    }
  }

  std::vector<ll> que;
  ll p = 0;

  memset( top, -1, sizeof(top) );

  rep( i, N ) rep( j, i ) if( !deg[comp(i,j)] )
    que.emplace_back( comp(i,j) );

  while( !que.empty() ) {
    std::vector<ll> vs;

    for( auto v : que ) {
      top[v] = p;
      
      for( auto u : G[v] ) {
        --deg[u];

        if( !deg[u] )
          vs.emplace_back( u );
      }
    }

    ++p;

    que = vs;
  }

  rep( i, N ) rep( j, i ) if( top[comp( i, j )] == -1 ) {
    std::cout << -1 << std::endl;

    return 0;
  }

  std::cout << p << std::endl;

  return 0;
}