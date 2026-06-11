#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
const int inf = 1e9 + 7;
const ll INF = 1e18;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
const int mod = 1000000007;
ll modpow(ll a, int b) { return b ? modpow(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<class T> inline void add(T &a, int b) { a += b; if (a >= mod) a -= mod; }



void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  // cin >> T;
  T = 1;

  while (T--) {
      solve();
  }
}

void solve() {
  int K, q;
  cin >> K >> q;
  vector<int> d(K);
  rep(i, K) cin >> d[i];

  while (q--) {
    int n, x, m;
    cin >> n >> x >> m;
    int k = K;

    chmin(k, n - 1);

    vector<int> d2 = d;
    rep(i, k) d2[i] %= m;

    // ">" を計算
    // a は単調増加数列だから普通 "<"
    // ">" となるのは, d2 < m に注意して, 商が 1 大きくなったとき
    ll a0 = x;
    ll an_1 = a0;

    ll sum = 0;
    rep(i, k) sum += d2[i];

    an_1 += n / k * sum;
    if (n % k == 0) {
      an_1 -= d2[k - 1]; // debuged
    } else {
      rep(i, n % k - 1) {
        an_1 += d2[i];
      }
    }

    ll ans = an_1 / m - a0 / m;
    // cout << endl << ans << endl;

    // "=" を計算
    sum = 0;
    rep(i, k) if (d2[i] == 0) sum++;
    ans += n / k * sum;
    if (n % k == 0) {
      if (d2[k - 1] == 0) ans--;
    } else {
      rep(i, n % k - 1) {
        if (d2[i] == 0) ans++;
      }
    }

    ans = n - 1 - ans; // "<" = 全体 - "=" - ">"
    cout << ans << endl;
  }
}
