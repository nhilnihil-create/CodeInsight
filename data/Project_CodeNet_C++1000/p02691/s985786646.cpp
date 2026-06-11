// https://atcoder.jp/contests/abc166/tasks/abc166_e

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
const int A_I_MAX = 1e9;

int N;
vector<int> A;

map<int, ll> mp1;
map<int, ll> mp2;

int main() {
  cin >> N;
  A = vector<int>(N);
  REP(i, N) cin >> A[i];

  REP(i, N) {
    mp1[i + 1 + A[i]]++;
    mp2[i + 1 - A[i]]++;
  }

  ll ans = 0;
  for (auto it = mp1.begin(); it != mp1.end(); it++) {
    int k = it->first;
    ans += mp1[k] * mp2[k];
  }

  cout << ans << endl;
}
