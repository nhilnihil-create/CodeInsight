// https://atcoder.jp/contests/abc166/tasks/abc166_b

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

const int N_MAX = 100;
const int K_MAX = 100;

int N, K;
vector<int> d;
vector<vector<int>> A;

vector<int> c;

int main() {
  cin >> N >> K;
  d = vector<int>(K);
  A = vector<vector<int>>(K);
  REP(i, K) {
    cin >> d[i];
    A[i] = vector<int>(d[i]);
    REP(j, d[i]) cin >> A[i][j];
  }

  c = vector<int>(N, 0);
  REP(i, K) REP(j, d[i]) c[A[i][j] - 1]++;

  int ans = 0;
  REP(i, N) if (c[i] == 0) ans++;
  cout << ans << endl;
}
