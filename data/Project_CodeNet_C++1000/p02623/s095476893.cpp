// https://atcoder.jp/contests/abc172/tasks/abc172_c

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

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

//------------------------------------------------------------------------------
const int N_MAX = 200000;
const int M_MAX = 200000;
const int K_MAX = 1e9;
const int A_I_MAX = 1e9;
const int B_I_MAX = 1e9;

int N, M, K;

vector<int> AB;

int main() {
  cin >> N >> M >> K;

  AB = vector<int>(N + M + 1);
  REP(i, N) cin >> AB[N - 1 - i];
  REP(i, M) cin >> AB[N + i];
  AB[N + M] = 0;

  // DUMP(AB);

  int ans = 0;
  int s = 0;
  int t = 0;
  int sum = 0;
  while (true) {
    while (t <= M + N && sum <= K) {
      if (s <= N && t >= N) {
        // cout << "[" << s << "," << t << ") : " << sum << endl;
        chmax(ans, t - s);
      }
      sum += AB[t++];
    }
    if (sum <= K) break;
    sum -= AB[s++];
  }

  cout << ans << endl;
}
