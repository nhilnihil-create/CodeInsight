// https://atcoder.jp/contests/abc161/tasks/abc161_f

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#if DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const ll N_MAX = 1e12;

ll N;

int count(ll k) {
  ll n = N;
  if (n % k == 1) return 1 + (k * k + 1 < n);
  while (n % k == 0) n /= k;
  return n % k == 1;
}

int main() {
  cin >> N;

  int ans = 0;
  for (ll k = 2; k * k <= N; k++) ans += count(k);
  ans += 1 + (N > 2);

  cout << ans << endl;
}
