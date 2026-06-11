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
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
const ll INF = 1ll<<60;

ll N, M;
std::string S;
std::vector<ll> vs;

int main()
{
  std::cin >> N >> M >> S;

  ll p = N;

  while( p > 0 )
  {
    bool upd = false;

    for( int i = M; i >= 1; --i )
    {
      if( p-i >= 0 && S[p-i] == '0' )
      {
        vs.emplace_back( i );
        p -= i;
        upd = true;
        break;
      }
    }

    if( !upd )
    {
      std::cout << -1 << std::endl;
      
      return 0;
    }
  }

  if( p )
  {
    std::cout << -1 << std::endl;

    return 0;
  }

  std::reverse( all(vs) );

  rep( i, vs.size() )
    std::cout << vs[i] << (i==vs.size()-1?'\n':' ');

  return 0;
}