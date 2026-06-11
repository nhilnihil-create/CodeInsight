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
ll S, T;
std::vector<std::vector<P>> G;
std::vector<ll> dist;

ll id( ll v, ll m )
{ return v*3+m; } 

void dijkstra( ll s, std::vector<std::vector<P>> &G, std::vector<ll> &dist )
{
  std::priority_queue<P, std::vector<P>, std::greater<P>> pque;

  dist.assign( N*3+10, INF );
  dist[s] = 0;

  pque.emplace( dist[s], s );

  while( !pque.empty() )
  {
    P p = pque.top(); pque.pop();
    ll d = p.first, v = p.second;

    if( dist[v] < d )
      continue;

    for( auto u : G[v] )
    {
      if( chmin( dist[u.first], dist[v]+u.second ) )
        pque.emplace( dist[u.first], u.first );
    }
  }

  return;
}

void add_edge( ll u, ll v ) {
  rep( j, 3 ) {
    G[id(u,j)].emplace_back(id(v,(j+1)%3), 1);
  }

  return;
}

int main() {
  std::cin >> N >> M;

  G.resize( N*3+10 );

  rep( i, M ) {
    ll u, v;
    std::cin >> u >> v;
    --u; --v;

    add_edge( u, v );
  }

  std::cin >> S >> T;
  --S; --T;

  dijkstra( id(S,0), G, dist );

  std::cout << (dist[id(T,0)]==INF ? -1 : dist[id(T,0)]/3) << endl;

  return 0;
}