// https://atcoder.jp/contests/abc161/tasks/abc161_e

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#if DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int N_MAX = 2*1e5;

int N, K, C;
string S;

vector<int> dp_l;
vector<int> dp_r;

int main() {
  cin >> N >> K >> C;
  cin >> S;

  int D = C + 1;
  dp_l = vector<int>(N);
  REP(i, N) {
    dp_l[i] = (i - D >= 0 ? dp_l[i - D] : 0) + (S[i] == 'o');
    if (i > 0) dp_l[i] = max(dp_l[i], dp_l[i - 1]);
  }
  dp_r = vector<int>(N);
  for (int i = N - 1; i >= 0; i--) {
    dp_r[i] = (i + D < N ? dp_r[i + D] : 0) + (S[i] == 'o');
    if (i < N - 1) dp_r[i] = max(dp_r[i], dp_r[i + 1]);
  }

  REP(i, N) {
    int w = 0;
    if (i > 0) w += dp_l[i - 1];
    if (i < N - 1) w += dp_r[i + 1];
    if (w < K) cout << (i + 1) << endl;
  }
}
