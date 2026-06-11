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

ll N, K;
ll A[510], S;

std::vector<ll> divisors( ll x )
{
  std::vector<ll> ret;

  for( ll i = 1; i*i <= x; ++i ) if( x % i == 0 )
  {
    ret.emplace_back( i );

    if( i != x/i )
      ret.emplace_back( x/i );
  }

  return ret;
}

int main()
{
  std::cin >> N >> K;

  rep( i, N )
    std::cin >> A[i], S += A[i];

  auto ds = divisors( S );

  std::sort( ds.rbegin(), ds.rend() );

  for( auto d : ds )
  {
    //printf( "[%lld]\n", d );

    ll sum = 0;
    std::vector<ll> vs;

    rep( i, N )
    {
      if( A[i] % d == 0 )
        continue;

      ll q = A[i]/d;
      ll ub = (q+1)*d, lb = q*d;
      ll a = (ub-A[i]), b = (A[i]-lb);

      sum += a;
      vs.emplace_back( a );
    }

    std::sort( vs.rbegin(), vs.rend() );

    if( sum % d )
      continue;

    ll x = sum/d;
    ll cnt = 0;

    rep( i, x )
      cnt += d-vs[i];
  
    if( cnt <= K )
    {
      std::cout << d << std::endl;

      return 0;
    }
  }

  return 0;
}