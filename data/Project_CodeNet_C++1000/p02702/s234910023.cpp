// https://atcoder.jp/contests/abc164/tasks/abc164_d

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DEBUG 0
#if DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int S_MAX = 200000;
const int MOD = 2019;

string S;

int N;
vector<int> v;
map<int, int> mp;

int main() {
  cin >> S;
  N = S.size();

  v = vector<int>(N);
  reverse(S.begin(), S.end());

  int w = 0;
  int mag = 1;
  REP(i, N) {
    int d = S[i] - '0';
    v[i] = w = (d * mag % MOD + w) % MOD;
    mp[v[i]]++;
    mag = mag * 10 % MOD;
  }

  ll ans = mp[0];
  REP(i, N - 1) {
    mp[v[i]]--;
    ans += mp[v[i]];
#if DEBUG
    cout << i << "," << v[i] << "," << mp[v[i]] << endl;
#endif
  }

  cout << ans << endl;
}
