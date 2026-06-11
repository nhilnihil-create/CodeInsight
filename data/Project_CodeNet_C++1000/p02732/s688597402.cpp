// https://atcoder.jp/contests/abc159/tasks/abc159_d

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define ITR(c,it)  for(auto it = c.begin(); it != c.end(); it++)

#if DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int N_MAX = 2*1e5;

int N;
vector<int> A;

map<int, int> mp;

int main() {
  cin >> N;
  A = vector<int>(N);
  REP(i, N) {
    cin >> A[i];
    mp[A[i]]++;
  }

  ll sum = 0LL;
  ITR(mp, it) {
    ll c = it-> second;
    sum += c * (c - 1) / 2;
  }

  REP(k, N) {
    int c = mp[A[k]];
    ll ans = sum - c + 1;
    cout << ans << endl;
  }
}
