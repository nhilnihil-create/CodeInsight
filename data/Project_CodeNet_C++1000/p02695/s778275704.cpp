// https://atcoder.jp/contests/abc165/tasks/abc165_c

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

//------------------------------------------------------------------------------
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

//------------------------------------------------------------------------------

const int N_MAX = 10;
const int M_MAX = 10;
const int Q_MAX = 50;
const int D_I_MAX = 1e5;

struct Cond {
  int a, b, c, d;
};

int N, M, Q;
vector<vector<Cond>> qs;

int dfs(vector<int> X, int v) {
  int b = X.size();
  if (b == N) return v;
  int ret = 0;
  int xx = *X.rbegin();
  FOR(i, xx, M) {
    vector<int> Y = X;
    Y.push_back(i);
    int v2 = v;
    for (auto q : qs[b]) {
      if (q.c == Y[b] - Y[q.a]) v2 += q.d;
    }
    chmax(ret, dfs(Y, v2));
  }
  return ret;
}

int main() {
  cin >> N >> M >> Q;
  qs = vector<vector<Cond>>(N, vector<Cond>());
  REP(i, Q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    qs[b].push_back({a, b, c, d});
  }

  vector<int> X = { 1 };
  int ans = dfs(X, 0);
  cout << ans << endl;
}
