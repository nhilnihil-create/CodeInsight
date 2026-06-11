// https://atcoder.jp/contests/abc167/tasks/abc167_c

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

const int N_MAX = 12;
const int M_MAX = 12;
const int X_MAX = 1e5;
const int C_I_MAX = 1e5;
const int A_IJ_MAX = 1e5;
const int INF = 1e9;

int N, M, X;
vector<int> C;
vector<vector<int>> A;

int main() {
  cin >> N >> M >> X;
  C = vector<int>(N);
  A = vector<vector<int>>(N, vector<int>(M));
  REP(i, N) {
    cin >> C[i];
    REP(j, M) cin >> A[i][j];
  }

  int ans = INF;
  REP(s, 1 << N) {
    int cost = 0;
    vector<int> v = vector<int>(M, 0);
    REP(i, N) {
      if (s >> i & 1) {
        cost += C[i];
        REP(j, M) v[j] += A[i][j];
      }
    }
    bool ok = true;
    REP(j, M) if (v[j] < X) ok = false;
    if (ok) ans = min(ans, cost);
  }

  if (ans < INF) cout << ans << endl;
  else cout << -1 << endl;
}
