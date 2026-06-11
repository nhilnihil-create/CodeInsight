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

int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

int h, w;
char c[101][101];

int dijkstra()
{
  pqg<pair<int,pii>> que;
  que.em(0, mp(0, 0));

  int dis[101][101];
  rep(i, 101) rep(j, 101) dis[i][j] = inf;
  dis[0][0] = 0;

  while (!que.empty()) {
    auto p = que.top(); que.pop();
    int x = p.se.fi, y = p.se.se, d = p.fi;

    if (dis[y][x] < d) continue;

    rep(i, 2) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

      int nd = d + (c[y][x] == '.' && c[ny][nx] == '#');
      if (dis[ny][nx] > nd) {
        dis[ny][nx] = nd;
        que.em(nd, mp(nx, ny));
      }
    }
  }

  int ret = dis[h-1][w-1];
  if (c[0][0] == '#') ++ret;

  return ret;
}

signed main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> c[i][j];

  cout << dijkstra() << endl;
}
