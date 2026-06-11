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
ll A[200010], F[200010];
ll S[200010];

int main()
{
  std::cin >> N >> K;

  rep( i, N )
    std::cin >> A[i];

  rep( i, N )
    std::cin >> F[i];

  std::sort( A, A+N, std::greater<ll>() );
  std::sort( F, F+N );

  ll ub = 0;

  rep( i, N )
    chmax( ub, A[i]*F[i] );

  ll ng = -1, ok = ub+1;

  while( ok-ng > 1 ) {
    ll mid = (ng+ok)/2;

    auto C = [&]( ll x ) {
      ll sum = 0;

      rep( i, N )
        sum += std::max( A[i]-x/F[i], 0ll );

      return sum <= K;
    };

    (C(mid) ? ok : ng) = mid;
  }

  std::cout << ok << std::endl;

  return 0;
}