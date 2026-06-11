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

ll N;
ll adj[510][510];
ll ptr = 1;

void rec( const std::vector<ll> &vs, ll lev )
{
  if( vs.size() == 1 )
    return;

  std::vector<ll> vs1, vs2;

  rep( i, vs.size()/2 )
    vs1.emplace_back( vs[i] );
  repi( j, vs.size()/2, vs.size() )
    vs2.emplace_back( vs[j] );

  rep( i, vs.size()/2 ) repi( j, vs.size()/2, vs.size() )
    adj[vs[i]][vs[j]] = lev;

  rec( vs1, lev+1 );
  rec( vs2, lev+1 );

  return;
}

int main()
{
  std::cin >> N;

  std::vector<ll> vs( N );
  std::iota( all(vs), 0 );

  rec( vs, 1 );

  rep( i, N-1 ) repi( j, i+1, N )
    std::cout << adj[i][j] << (j==N-1?'\n':' ');

  return 0;
}