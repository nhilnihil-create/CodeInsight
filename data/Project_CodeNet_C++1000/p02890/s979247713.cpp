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
ll A[300010];
std::map<ll, ll> cnt, mp;
ll S[300010];

ll sum;

int main()
{
  std::cin >> N;

  rep( i, N )
    std::cin >> A[i], ++cnt[A[i]], sum += A[i];

  rep( i, 300001 ) if( cnt.count( i ) ) repi( j, 1, cnt[i]+1 )
    ++mp[j];

  rep( i, N+2 )
    S[i+1] = S[i]+mp[i];

  repi( K, 1, N+1 )
  {
    ll ng = -1, ok = N+1;

    while( ok-ng > 1 )
    {
      ll mid = (ng+ok)/2;

      auto C = [&]( ll x, ll k ) {
        return S[x+1] < k*x;
      };

      (C(mid, K) ? ok : ng) = mid;
    }

    std::cout << ok-1 << std::endl;
  }

  return 0;
}