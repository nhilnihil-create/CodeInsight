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
const ll INF = 1ll<<60;

std::string N;
ll dp[1000010][2];

int main()
{
  std::cin >> N;

  std::reverse( all(N) );

  N += "0";

  ll n = N.size();

  rep( i, n+1 ) rep( j, 2 )
    dp[i][j] = INF;

  dp[0][0] = 0;

  rep( i, n ) rep( j, 2 )
  {
    ll x = N[i]-'0';

    x += j;

    rep( a, 10 )
    {
      ll b = a-x;
      ll nj = 0;

      if( b < 0 )
      {
        nj = 1;
        b += 10;
      }

      chmin( dp[i+1][nj], dp[i][j]+a+b );
    }
  }

  std::cout << dp[n][0] << std::endl;

  return 0;
}