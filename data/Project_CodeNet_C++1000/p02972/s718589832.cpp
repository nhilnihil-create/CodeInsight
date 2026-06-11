// https://atcoder.jp/contests/abc134/tasks/abc134_d

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
#define DUMP2D(a) REP(_i, a.size()) DUMP(a[_i]); cout << endl

const int N_MAX = 2*1e5;
const int MOD = 2;

int N;
vector<int> a;
int M;
vector<int> b;

int main() {
  cin >> N;
  a = vector<int>(N);
  REP(i, N) cin >> a[i];

  M = 0;
  b = vector<int>(N, 0);
  for (int i = N; i > 0; i--) {
    b[i - 1] = a[i - 1];
    for(int j = i * 2; j <= N; j += i) {
      b[i - 1] ^= b[j - 1];
    }
    M += b[i - 1];
  }

  cout << M << endl;
  REP(i, N) if(b[i]) cout << (i + 1) << endl;
}
