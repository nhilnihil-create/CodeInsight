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
ll A[200010], B[200010];
std::priority_queue<P> pque;
ll ans;

int main()
{
  std::cin >> N;

  rep( i, N )
    std::cin >> A[i];
  
  rep( i, N )
  {
    std::cin >> B[i];

    if( A[i] < B[i] )
      pque.emplace( B[i], i );
  }

  while( !pque.empty() )
  {
    P p = pque.top(); pque.pop();
    ll idx = p.second;

    ll mod = B[(idx-1+N)%N]+B[(idx+1)%N];

    if( B[idx]-A[idx] >= mod )
    {
      ans += (B[idx]-A[idx])/mod;
      B[idx] = A[idx] + (B[idx]-A[idx]) % mod;

      if( B[idx] > A[idx] )
        pque.emplace( B[idx], idx );
    }
  }

  rep( i, N ) if( A[i] != B[i] )
  {
    std::cout << -1 << std::endl;

    return 0;
  }

  std::cout << ans << std::endl;

  return 0;
}