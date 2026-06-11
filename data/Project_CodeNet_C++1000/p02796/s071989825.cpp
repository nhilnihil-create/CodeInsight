#include <bits/stdc++.h>
#define int long long
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


signed main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  int n; cin >> n;
  vpi a(n);

  rep(i, n) {
    int x, l; cin >> x >> l;
    a[i].fi = x - l;
    a[i].se = x + l;
  }

  sort(all(a),[](pii x, pii y) {
    return x.se < y.se;
  });

  int fin = a[0].se, cnt = 0;
  rep2(i, 1, n-1) {
    if (fin > a[i].fi) ++cnt;
    else fin = a[i].se;
  }

  cout << n - cnt << endl;
}
