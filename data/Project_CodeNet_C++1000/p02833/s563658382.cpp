#include <bits/stdc++.h>
using namespace std;


/* エイリアス */
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define endl '\n'

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair


/* 関数マクロ */
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n, m) for (ll i = n; i <= m; ++i)
#define rep3(i, n, m) for (ll i = n; i >= m; --i)
#define all(v) v.begin(), v.end()
#define si(v) int(v.size())
#define UNIQUE(v) sort(all(v)), v.erase(unique(all(v)),v.end())


/* 定数 */
const ll mod = 1e9 + 7;
const ll infll = (1LL << 62) - 1;
const ll inf = (1LL << 30) - 1;


/* その他 */
template<class S, class T> inline bool chmax(S &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class S, class T> inline bool chmin(S &a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n; cin >> n;

  if (n % 2) {
    cout << 0 << endl;
    return 0;
  }

  int cnt = 0;
  ll tmp = n;

  while (tmp) {
    ++cnt;
    tmp /= 5;
  }

  ll c[30] = {};
  ll ans = 0;

  rep3(i, cnt, 1) {
    ll v = 2;
    rep(j, i) v *= 5LL;

    c[i+1] += c[i+2];
    c[i] = (n / v) - c[i+1];
    ans += i * c[i];
  }

  cout << ans << endl;
}
