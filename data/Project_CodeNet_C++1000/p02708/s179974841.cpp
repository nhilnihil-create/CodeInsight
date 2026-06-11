// https://atcoder.jp/contests/abc163/tasks/abc163_d

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DEBUG 0
#if DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int N_MAX = 2*1e5;
const int MOD = 1e9+7;

int N, K;

int main() {
  cin >> N >> K;

  ll ans = 0;
  FOR(i, K, N + 1) {
    ll tmp = i;
    tmp = tmp * (N + 1 - i) % MOD;;
    tmp = (tmp + 1) % MOD;
    ans = (ans + tmp) % MOD;
  }

  cout << ans << endl;
}
