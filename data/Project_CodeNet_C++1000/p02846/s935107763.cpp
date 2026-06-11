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

ll T1, T2;
ll A1, A2;
ll B1, B2;

int main()
{
  std::cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

  ll P = (A1-B1)*T1, Q = (A2-B2)*T2;

  if( P > 0 ) {
    P *= -1;
    Q *= -1;
  }

  if( P+Q < 0 )
    std::cout << 0 << std::endl;
  else if( P+Q == 0 )
    std::cout << "infinity" << std::endl;
  else {
    ll S = -P/(P+Q), T = (-P)%(P+Q);

    if( T == 0 )
      std::cout << 2*S << std::endl;
    else
      std::cout << 2*S+1 << std::endl;
  }

  return 0;
}