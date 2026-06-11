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

ll k, q;
ll d[5010], S[5010], zS[5010];

int main() {
  std::cin >> k >> q;

  rep( i, k )
    std::cin >> d[i];

  rep( t, q ) {
    ll n, x, m;
    std::cin >> n >> x >> m;

    ll cnt = n-1;

    ll a = x;

    S[0] = 0;
    zS[0] = 0;

    rep( i, k ) {
      S[i+1] = S[i]+d[i]%m;
      zS[i+1] = zS[i]+(d[i]%m == 0);
    }

    a += S[k]*((n-1)/k)+S[(n-1)%k];
    cnt -= zS[k]*((n-1)/k)+zS[(n-1)%k];

    cnt -= a/m-x/m;

    std::cout << cnt << endl;
  }

  return 0;
}