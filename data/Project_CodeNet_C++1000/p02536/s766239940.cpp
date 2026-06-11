
// Problem: C - Connect Cities
// Contest: AtCoder - ACL Beginner Contest
// URL: https://atcoder.jp/contests/abl/tasks/abl_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define ll long long int
#define ii int
#define du double
#define jmp "\n"
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define printv(v)     \
  for (auto x : v)    \
    cout << x << " "; \
  cout << jmp;
#define vi vector<int>
#define vb vector<bool>
#define ump unordered_map
#define SORT(v) sort(v.begin(), v.end())
#define REV(x) reverse(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define SET(x, a) memset(x, a, sizeof(x))
#define si(x) x.size()
#define ff first
#define ss second
#define iin insert
#define deb(x) cout << "test " << #x << "=" << x << jmp
#define deb2(x, y) cout << "test " << #x << "=" << x << "," << #y << "=" << y << jmp
using namespace std;
const ll nax = 1e5 + 5;
vl g[nax];
vb vis(nax);
void dfs(ll u)
{
  vis[u] = 1;
  for (auto x : g[u])
  {
    if (!vis[x])
      dfs(x);
  }
}
void solve()
{
  ll n, m, ctr = 0;
  cin >> n >> m;
  for (ll i = 0; i < m; i++)
  {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  fill(all(vis), 0);
  for (ll i = 0; i < n; i++)
    if (!vis[i])
    {
      dfs(i);
      ctr++;
    }
  cout << ctr - 1 << jmp;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}