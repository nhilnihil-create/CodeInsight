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
ll A[100010];
ll l[100010], r[100010];

int main()
{
  std::cin >> N;

  rep( i, N+1 )
    std::cin >> A[i];

  l[N] = A[N], r[N] = A[N];

  repd( i, N )
  {
    l[i] = (l[i+1]+1)/2+A[i];
    r[i] = r[i+1]+A[i];
  }

  if( l[0] <= 1 && 1 <= r[0] )
  {
    ll p = 1;
    ll ans = 1;

    repi( i, 1, N+1 )
    {
      p *= 2;
      p = std::min( p, r[i] );
      ans += p;
      p -= A[i];
    }

    std::cout << ans << std::endl;
  }
  else
    std::cout << -1 << std::endl;

  return 0;
}