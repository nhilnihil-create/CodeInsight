#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"


#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << "\n"; }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}


#line 2 "tmp.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<pair<ll, int>> a(n);
  REP(i, n) {
    int _a;
    cin >> _a;
    a[i] = {_a, i + 1};
  }
  sort(a.rbegin(), a.rend());
  vector<vl> dp(n + 1, vl(n + 1, 0));
  FOR(i, 1, n + 1) {
    REP(j, i + 1) {
      if (j <= i - 1)
        chmax(dp[i][j], dp[i - 1][j] + abs(n - (i - 1 - j) - a[i - 1].second) * a[i - 1].first);
      if (j > 0) {
        chmax(dp[i][j], dp[i - 1][j - 1] + (ll)abs(j - a[i - 1].second) * a[i - 1].first);
      }
    }
  }
  ll ans = 0;
  REP(i, n + 1) { chmax(ans, dp[n][i]); }
  cout << ans << endl;
  return 0;
}
