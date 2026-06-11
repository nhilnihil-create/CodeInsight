#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

std::string S;

int main()
{
  std::cin >> S;

  if( S.size() & 1 )
  { puts("No"); return 0; }

  bool fl = true;

  rep( i, S.size() )
  {
    if( i & 1 )
      fl &= S[i] == 'i';
    else
      fl &= S[i] == 'h';
  }

  puts( fl ? "Yes" : "No" );

  return 0;
}