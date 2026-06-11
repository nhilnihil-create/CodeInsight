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
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N, K;
ll A[200010], S[200010];
std::map<ll, ll> mp;
ll ans;

int main()
{
  std::cin >> N >> K;

  rep( i, N )
    std::cin >> A[i], --A[i];

  rep( i, N )
    S[i+1] = (S[i]+A[i]%K)%K;

  rep( i, N+1 )
  {
    ans += mp[S[i]%K];

    ++mp[S[i]%K];

    if( i-K+1 >= 0 )
      --mp[S[i-K+1]%K];
  }

  std::cout << ans << std::endl;

  return 0;
}