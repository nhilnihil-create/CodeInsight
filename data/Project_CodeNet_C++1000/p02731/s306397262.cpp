// https://atcoder.jp/contests/abc159/tasks/abc159_c

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

const int L_MAX = 1000;

int L;

int main() {
  cin >> L;
  double ans = pow((double) L / 3, 3);
  cout << fixed << setprecision(12);
  cout << ans << endl;
}
