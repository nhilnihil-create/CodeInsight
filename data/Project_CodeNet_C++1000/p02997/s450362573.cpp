// https://atcoder.jp/contests/abc131/tasks/abc131_e

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 100;

int N, K;

void solve() {
  int M = (N - 1) * (N - 2) / 2;
  if (K > M) {
    puts("-1");
    return;
  }
  printf("%d\n", N - 1 + M - K);
  FOR(i, 1, N - 1) {
    printf("%d %d\n", i, N);
  }
  int i = 1;
  int j = 2;
  REP(k, M - K) {
    printf("%d %d\n", i, j);
    j++;
    if (j >= N) {
      i++;
      j = i + 1;
    }
  }
}

void input() {
  scanf("%d%d", &N, &K);
}

int main() {
  input();
  solve();
  return 0;
}
