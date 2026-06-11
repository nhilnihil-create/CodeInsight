// https://atcoder.jp/contests/abc166/tasks/abc166_c

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

const int N_MAX = 1e5;
const int M_MAX = 1e5;
const int H_I_MAX = 1e9;

int N, M;
vector<int> H;
vector<bool> ps;

int main() {
  cin >> N >> M;
  H = vector<int>(N);
  REP(i, N) cin >> H[i];
  ps = vector<bool>(N, true);
  REP(i, M) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    if (H[A] <= H[B]) ps[A] = false;
    if (H[B] <= H[A]) ps[B] = false;
  }

  int ans = 0;
  REP(i, N) if (ps[i]) ans++;
  cout << ans << endl;
}
