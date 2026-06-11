#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n; cin >> n;
  vector<ll> cnt(3, -1);

  ll ans = 1;
  rep(i, n) {
    ll a; cin >> a;

    ll rem = 0;
    rep(j, 3) {
      if(cnt[j] == a - 1) ++rem;
    }
    ans *= rem;
    ans %= MOD;

    rep(j, 3) {
      if(cnt[j] == a - 1) {
        ++cnt[j];
        break;
      }
    }
  }

  cout << ans << endl;
}

// 0 1 2 0 1 0 1 2
// r r r g g b b gb
