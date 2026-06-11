// https://atcoder.jp/contests/abc163/tasks/abc163_c

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

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

int N;
// vector<int> A;

vector<int> ans;

int main() {
  cin >> N;
  // A = vector<int>(N - 1);
  // REP(i, N - 1) cin >> A[i];

  ans = vector<int>(N, 0);
  REP(i, N - 1) {
    int A;
    cin >> A;
    ans[A - 1]++;
  }

  REP(i, N) cout << ans[i] << endl;
}
