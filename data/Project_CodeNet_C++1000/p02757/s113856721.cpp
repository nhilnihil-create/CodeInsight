// https://atcoder.jp/contests/abc158/tasks/abc158_e

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

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

const int N_MAX = 2*1e5;
const int P_MAX = 10000;

int N, P;
string S;

vector<int> v;
map<int, int> mp;

int main() {
  cin >> N >> P;
  cin >> S;

  ll ans = 0;
  if (10 % P == 0) {
    REP(i, N) {
      int d = S[i] - '0';
      if (d % P == 0) {
        ans += i + 1;
      }
    }
  } else {
    v = vector<int>(N);
    reverse(S.begin(), S.end());

    int w = 0;
    int mag = 1;
    REP(i, N) {
      int d = S[i] - '0';
      v[i] = w = (d * mag % P + w) % P;
      mp[v[i]]++;
      mag = mag * 10 % P;
    }

    DUMP(v);

    ans = mp[0];
    REP(i, N - 1) {
      mp[v[i]]--;
      ans += mp[v[i]];
#if DEBUG
      cout << i << "," << v[i] << "," << mp[v[i]] << endl;
#endif
    }
  }

  cout << ans << endl;
}
