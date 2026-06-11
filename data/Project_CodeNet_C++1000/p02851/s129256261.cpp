// 2020-07-25 07:27:17
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
  vector<int> a(n+1, 0);
  rep(i, n) {
    cin >> a[i+1];
    a[i+1]--;
  }
  map<int, vector<int> > mp;
  int cur = 0;
  repc(i, n) {
    cur = (cur + a[i]) % k;
    mp[cur].push_back(i);
  }
  ll ans = 0;
  for(auto p : mp) {
    auto& v = p.second;
    int sz = v.size();
    int l = 0, r = 0;
    while(l < sz) {
      while(r < sz && v[r] - v[l] < k) {
        r++;
      }
      ans += r - l - 1;
      l++;
    }
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}