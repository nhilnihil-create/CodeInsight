#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp        make_pair
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

int inf(0x3fffffff);
int mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int n, x, y;
  cin >> n >> x >> y;
  x--, y--;
  vvi adj(n);
  rep(i, n - 1) {
    adj[i].pb(i + 1);
    adj[i + 1].pb(i);
  }
  adj[x].pb(y);
  adj[y].pb(x);

  vi cnt(n);
  for (int i = 0; i < n; i++) {
    unordered_map<int, int> dist;
    queue<int> q;
    dist[i] = 0;
    q.push(i);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      int d = dist[cur] + 1;
      for (int p : adj[cur]) {
        if (dist.count(p)) continue;

        cnt[d]++;
        dist[p] = d;
        q.push(p);
      }
    }
  }
  rep(i, n - 1) cout << cnt[i + 1] / 2 << '\n';

  return 0;
}
