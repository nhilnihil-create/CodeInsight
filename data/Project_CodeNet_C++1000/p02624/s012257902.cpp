// https://atcoder.jp/contests/abc172/tasks/abc172_d

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DEBUG 1
#if DEBUG
  #define _GLIBCXX_DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const ll N_MAX = 1e7;

ll N;

int main() {
  cin >> N;

  ll ans = 0;
  ll i;
  for (i = 1; i * 2 <= N; i++) {
    ll j = N / i;
    ans += i * j * (j + 1) / 2;
  }
  if (i <= N) ans += (N + i) * (N - i + 1) / 2;
  cout << ans << endl;
}
