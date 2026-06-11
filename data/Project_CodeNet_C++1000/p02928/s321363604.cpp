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

ll repeat_squaring_mod(ll N, ll P) {
  if(P == 0) return 1;
  if(P % 2 == 0) {
    ll t = repeat_squaring_mod(N, P / 2);
    return t * t % MOD;
  }
  return N * repeat_squaring_mod(N, P - 1);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n,k; cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  rep(i, n) {
    for(int j = i + 1; j < n; ++j) {
      if(a[j] > a[i]) {
        ans += k * (k-1) / 2;
        ans %= MOD;
      } else if(a[i] > a[j]) {
        ans += k * (k+1) / 2;
        ans %= MOD;
      }
    }
  }

  cout << ans << endl;
}
