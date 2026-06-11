// https://atcoder.jp/contests/abc166/tasks/abc166_d

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

const int X_MAX = 1e9;

ll X;

int main() {
  cin >> X;

  for (ll A = 120L; A > 0; A--) {
    for (ll B = A - 1; B >= -120L; B--) {
      ll d = A * A * A * A * A - B * B * B * B * B;
      if (d == X) {
        cout << A << " " << B << endl;
        return 0;
      }
    }
  }
}
