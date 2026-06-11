// 2020-07-26 11:08:57
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int n, k;
  cin >> n >> k;
  int lim = (n-1) * (n-2) / 2;
  if(k > lim) {
    cout << -1 << '\n';
    return;
  }
  int m = n-1+lim-k;
  cout << m << '\n';
  REPC(i, 2, n) {
    cout << 1 << ' ' << i << '\n';
  }
  REPC(i, 2, n-1) REPC(j, i+1, n) {
    if(k < lim) {
      cout << i << ' ' << j << '\n';
      lim--;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}