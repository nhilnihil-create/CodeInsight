// https://atcoder.jp/contests/abc171/tasks/abc171_e

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

const int N_MAX = 200000;
const int A_I_MAX = 1e9;

int N;
vector<int> a;

int main() {
  cin >> N;
  a = vector<int>(N);
  REP(i, N) cin >> a[i];

  int b = 0;
  REP(i, N) b ^= a[i];

  REP(i, N) {
    cout << (b ^ a[i]);
    if (i == N - 1) cout << endl;
    else cout << " ";
  }
}
