// 2020-08-07 09:28:16
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

int n, s[20];
void print() {
  rep(i, n) {
    cout << char('a' + s[i]);
  }
  cout << '\n';
}
void rec(int mx, int d) {
  if(d == n) {
    print();
    return;
  }
  rep(i, mx+2) {
    s[d] = i;
    rec(max(mx, i), d+1);
  }
}
void answer() {
  cin >> n;
  rec(-1, 0);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}