// https://atcoder.jp/contests/abc153/tasks/abc153_f

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define ITR(c,it)  for(auto it = c.begin(); it != c.end(); it++)

#if 0
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(a) if (DEBUG) REP(_i, a.size()) DUMP(a[_i]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(a)
#endif

const int N_MAX = 2*1e5;
const int D_MAX = 1e9;
const int A_MAX = 1e9;
const int X_I_MAX = 1e9;
const int H_I_MAX = 1e9;

int N, D, A;
vector<int> X;
vector<int> H;

map<double, int> mp;
vector<int> k;

int main() {
  cin >> N >> D >> A;
  X = vector<int>(N);
  H = vector<int>(N);
  REP(i, N) cin >> X[i] >> H[i];

  REP(i, N) {
    mp[X[i]] = (i + 1);
    mp[X[i] + D * 2 + 0.5] = -(i + 1);
  }
  k = vector<int>(N);

  ll cur = 0;
  ITR(mp, it) {
    int i1 = it->second;
    int i = abs(i1) - 1;
    if (i1 > 0) {
      k[i] = max((ll) 0, (H[i] + A - 1) / A - cur);
      cur += k[i];
    } else {
      cur -= k[i];
    }
  }

  DUMP(k);

  ll ans = 0;
  REP(i, N) ans += k[i];
  cout << ans << endl;
}
