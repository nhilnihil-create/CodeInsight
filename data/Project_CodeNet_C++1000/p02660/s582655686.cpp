// https://atcoder.jp/contests/abc169/tasks/abc169_d

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

//------------------------------------------------------------------------------
map<ll, int> prime_factor(ll n) {
  map<ll, int> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

//------------------------------------------------------------------------------
const ll N_MAX = 1e12;

ll N;

int unique_div(int n) {
  int k = 1;
  while (n >= k) {
    n -= k++;
  }
  return k - 1;
}

int main() {
  cin >> N;

  auto mp = prime_factor(N);

  int ans = 0;
  for (auto p : mp) {
    int d = unique_div(p.second);
    // cout << "[" << p.first << "," << p.second << "," << d << "]" << endl;
    ans += d;
  }

  cout << ans << endl;
}
