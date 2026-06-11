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
#include <boost/multiprecision/cpp_int.hpp>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using ll = long long;
using P = std::pair<ll, ll>;

using namespace boost::multiprecision;

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
ll A[100010];
cpp_int r[100010];

int main()
{
  std::cin >> N;

  rep( i, N+1 )
    std::cin >> A[i];

  cpp_int rb = 1;

  rep( i, N+1 )
  {
    rb -= A[i];
    r[i] = rb;

    if( (rb <= 0 && i != N) || (rb < 0 && i == N) )
    {
      std::cout << -1 << std::endl;

      return 0;
    }

    rb *= 2;
  }

  ll ans = A[N];
  ll p = A[N];

  repd( i, N )
  {
    ll mi = std::min( p, (ll)r[i] )+A[i];
    ans += mi;
    p = mi;
  }

  std::cout << ans << std::endl;

  return 0;
}