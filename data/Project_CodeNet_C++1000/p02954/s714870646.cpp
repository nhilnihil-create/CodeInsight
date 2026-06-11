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

std::string S;
ll left[200000], right[200000];
ll cnt[200000];

int main() {
  std::cin >> S;

  ll N = S.size();
  ll prv = -1;

  rep( i, N ) {
    if( S[i] == 'R' )
      right[i] = i, prv = i;
    else
      right[i] = prv;
  }

  prv = -1;
  repd( i, N ) {
    if( S[i] == 'L' )
      left[i] = i, prv = i;
    else
      left[i] = prv;
  }

  rep( i, N ) {
    if( S[i] == 'R' ) {
      ll L = left[i];
      ll s = L-i;

      ++cnt[L-(s&1)];
    } else {
      ll R = right[i];
      ll s = i-R;

      ++cnt[R+(s&1)];
    }
  }

  rep( i, N )
    std::cout << cnt[i] << (i==N-1?'\n':' ');

  return 0;
}