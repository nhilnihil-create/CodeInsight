// https://atcoder.jp/contests/abc169/tasks/abc169_e

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

const int N_MAX = 2*1e5;
const int B_I_MAX = 1e9;

int N;
vector<int> A;
vector<int> B;

int main() {
  cin >> N;
  A = vector<int>(N);
  B = vector<int>(N);
  REP(i, N) cin >> A[i] >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int ans = 0;
  if (N % 2) {
    ans = B[N / 2] - A[N / 2] + 1;
  } else {
    ans = (B[N / 2] + B[N / 2 - 1]) - (A[N / 2]+ A[N / 2 - 1]) + 1;
  }

  cout << ans << endl;
}
