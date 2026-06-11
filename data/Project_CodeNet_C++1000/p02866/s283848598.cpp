#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  int first; cin >> first;
  if(first != 0) {
    cout << 0 << endl;
    return 0;
  }

  int maxd = -1;
  vector<int> cnt(100005, 0);
  cnt[0] = 1;
  rep(i, n-1) {
    int d; cin >> d;
    ++cnt[d];
    chmax(maxd, d);
  }

  if(cnt[0] != 1) {
    cout << 0 << endl;
    return 0;
  }

  ll mod = 998244353;
  ll ans = 1;
  rep1(i, maxd) {
    if(cnt[i] == 0) {
      cout << 0 << endl;
      return 0;
    }

    rep(j, cnt[i]) {
      ans = ans * cnt[i-1] % mod;
    }
  }

  cout << ans << endl;
  return 0;
}
