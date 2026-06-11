// https://atcoder.jp/contests/abc173/tasks/abc173_f

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

const int N_MAX = 2*1e5;

ll N;
vector<int> u;
vector<int> v;

int main() {
  cin >> N;
  u = vector<int>(N-1);
  v = vector<int>(N-1);
  REP(i, N-1) cin >> u[i] >> v[i];

  ll ans = (N * N * N + N * N * 3 + N * 2) / 6;
  REP(i, N - 1) {
    ll a = min(u[i], v[i]);
    ll b = max(u[i], v[i]);
    ans -= a * (N - b + 1);
  }
  cout << ans << endl;
}
