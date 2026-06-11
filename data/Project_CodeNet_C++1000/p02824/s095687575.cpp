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

ll N, M, V, P;
ll A[100010];

bool C( ll x )
{
  ll ret = M*(N-x-1+1+P-1);

  repi( i, P-1, x )
    ret += M+A[x]-A[i];//, std::cout << M+A[x]-A[i] << std::endl;;

  //std::cout << "[" << x << "]" << std::endl;
  //std::cout << ret << std::endl;

  return A[x]+M >= A[P-1] && ret >= M*V;
}

int main()
{
  std::cin >> N >> M >> V >> P;

  rep( i, N )
    std::cin >> A[i];

  std::sort( A, A+N, std::greater<ll>() );

  //rep( i, N )
    //std::cout << A[i] << std::endl;

  ll ng = 0, ok = N;

  while( ok-ng > 1 )
  {
    ll mid = (ng+ok)/2;

    (!C(mid) ? ok : ng) = mid;
  }

  std::cout << ok << std::endl;

  return 0;
}