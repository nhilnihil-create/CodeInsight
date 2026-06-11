#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

int keta(int n) {
  if(n == 0) return 1;
  return int(log10(n))+1;
}
void answer() {
  int n, m;
  cin >> n >> m;
  vector<int> s(m), c(m);
  rep(i, m) {
    cin >> s[i] >> c[i];
    s[i]--;
  }
  rep(i, 1000) {
    string str = to_string(i);
    bool ok = true;
    ok = (n == str.size());
    if(!ok) continue;
    rep(j, m) {
      ok &= (str[s[j]]-'0' == c[j]);
    }
    if(ok) {
      cout << i << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}