// https://atcoder.jp/contests/abc155/tasks/abc155_e

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define DEBUG 0
#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#if DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int N_MAX = 1'000'000;

string N;

int L;
vector<vector<int>> dp;


int main() {
  cin >> N;

  L = N.size();

  dp = vector<vector<int>>(2, vector<int>(2));
  auto cur = dp[0];
  auto nxt = dp[1];
  cur[0] = 0;
  cur[1] = 1;

  DUMP(cur);

  REP(i, L) {
    int d = N[i] - '0';
    REP(j, 2) {
      int k = d + j;
      if (k == 0) {
        nxt[j] = cur[0];
      } else if (k <= 9) {
        nxt[j] = min(k + cur[0], 10 - k + cur[1]);
      } else {
        nxt[j] = cur[1];
      }
    }
    swap(cur, nxt);
    DUMP(cur);
  }

  int ans = cur[0];
  cout << ans << endl;
}
