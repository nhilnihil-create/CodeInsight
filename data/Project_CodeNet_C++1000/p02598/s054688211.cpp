// https://atcoder.jp/contests/abc174/tasks/abc174_e

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

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

const int N_MAX = 2*1e5;
const int K_MAX = 1e9;
const int A_I_MAX = 1e9;

int N, K;
vector<int> A;

bool C(double l) {
  ll c = 0;
  REP(i, N) {
    c += ceil(A[i] / l);
  }
  return c <= (N + K);
}

int main() {
  cin >> N >> K;
  A = vector<int>(N);
  REP(i, N) cin >> A[i];

  sort(A.begin(), A.end());

  double hi = A[N - 1];
  double lo = 0;
  REP(i, 100) {
    double mi = (hi + lo) / 2;
    if (C(mi)) hi = mi;
    else lo = mi;
  }

  cout << (int) ceil(hi) << endl;
}
