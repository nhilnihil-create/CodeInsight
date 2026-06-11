// https://atcoder.jp/contests/abc174/tasks/abc174_d

#include <bits/stdc++.h>
using namespace std;

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

const int N_MAX = 200000;

int N;
string c;

int main() {
  cin >> N;
  cin >> c;

  int ans = 0;
  int s = 0;
  int t = N - 1;
  while (s < t) {
    if (c[s] == 'R') s++;
    else if (c[t] == 'W') t--;
    else {
      ans++;
      s++;
      t--;
    }
  }

  cout << ans << endl;
}
