// https://atcoder.jp/contests/abc160/tasks/abc160_d

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

const int N_MAX = 2*1e3;

int N, X, Y;
vector<int> ans;

int step1(int i, int j) {
  if (i >= X) return 0;
  return min(j, X) - i;
}

int step2(int i, int j) {
  if (i > Y || j < X) return 0;
  i = max(i, X);
  j = min(j, Y);
  return min(j - i, (i - X) + 1 + (Y - j));
}

int step3(int i, int j) {
  if (j <= Y) return 0;
  return j - max(i, Y);
}

int main() {
  cin >> N >> X >> Y;
  X--; Y--;
  ans = vector<int>(N, 0);
  REP(j, N) REP(i, j) {
    int d = step1(i, j) + step2(i, j) + step3(i, j);
    ans[d]++;
  }
  FOR(d, 1, N - 1) {
    cout << ans[d] << endl;
  }
}
