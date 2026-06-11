#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define MOD_1_000_000_007 (1000000007LL)
#define LINF (1LL<<60)
#define rep(i, n)   for (long long i = 0; i <  (long long)(n); i++)
#define rep1(i, n)  for (long long i = 1; i <  (long long)(n); i++)
#define rep2(i, n)  for (long long i = 2; i <  (long long)(n); i++)
#define rep0c(i, n) for (long long i = 0; i <= (long long)(n); i++)
#define rep1c(i, n) for (long long i = 1; i <= (long long)(n); i++)
#define rep2c(i, n) for (long long i = 2; i <= (long long)(n); i++)
#define repc0(n, i) for (long long i = (long long)(n); i >= 0; i--)
#define repc1(n, i) for (long long i = (long long)(n); i >= 1; i--)
#define repc2(n, i) for (long long i = (long long)(n); i >= 2; i--)
#define REP(i, n, m) for (long long i = (long long)(n); i < (long long)(m); i++)

namespace solver {
  using namespace std;
  typedef long long ll;

  string S, T, ABC = "abcdefghijklmnopqrstuvwxyz";
  ll table[100010][26];

  void init() {
    cin >> S;
    cin >> T;
  }

  void solve() {
    string S2 = S+S;
    size_t s_size = S.size();
    size_t t_size = T.size();
    vector<ll> vec[26];
    rep(i, 2*s_size) {
      vec[ABC.find(S2[i])].push_back(i);
    }
    rep(i, 26) {
      if(vec[i].size() == 0) rep(j, s_size) table[j][i] = -1;
      else {
        ll cur = 0;
        for(const auto& j : vec[i]) {
          REP(k, cur, min(j+1, (ll)s_size)) table[k][i] = j % s_size;
          cur = j+1;
        }
      }
    }
    ll cur = 0, ans = 0;
    rep(i, t_size) {
      ll next_cur = table[cur][ABC.find(T[i])];
      if(next_cur == -1) {
        ans = -1;
        break;
      }
      if(cur <= next_cur) ans += next_cur+1-cur;
      else ans += s_size + (next_cur+1-cur);
      cur = (next_cur+1) % s_size;
    }
    cout << ans << endl;
  }
}

int main() {
  solver::init();
  solver::solve();
  return 0;
}