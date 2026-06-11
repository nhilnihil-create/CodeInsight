// https://atcoder.jp/contests/abc133/tasks/abc133_d

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) cout << a[_i] << (_i + 1 == n ? endl : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) cout << a[_i][_j] << (_j + 1 == m ? endl : ' '); cout << endl

const int N_MAX = 1e5-1;
const int A_I_MAX = 1e9;

int N;
vector<int> A;

int main() {
  cin >> N;
  A = vector<int>(N);
  REP(i, N) cin >> A[i];

  int x = 0;
  REP(i, N) {
    if (i % 2) x -= A[i];
    else x += A[i];
  }
  REP(i, N) {
    cout << x;
    if (i + 1 == N) cout << endl;
    else cout << " ";
    x = A[i] * 2 - x;
  }
}
