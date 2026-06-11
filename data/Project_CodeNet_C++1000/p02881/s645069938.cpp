#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using ll = long long;
using namespace std;

const long long MOD = 1000000007;
const ll LINF = 1LL << 50;


int main() {
  ll N;
  cin >> N;

  ll nend = 0;

  while(nend*nend < N){
    nend += 1;
  }

  ll ans = LINF;
  for (ll n = 1; n <= nend; n++){
    if (N%n == 0){
      ans = min({ans,n+N/n-2});
    }
  }
  cout << ans << endl;
}
