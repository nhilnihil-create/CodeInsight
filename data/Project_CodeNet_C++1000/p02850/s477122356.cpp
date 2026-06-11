#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
vi G[200100];
int ans = 0;
int check[200100];
int main() {
  map<P,int> mp;
  int n;
  cin >> n;
  vi a(n-1),b(n-1);
  rep(i, n - 1) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    a[i] = x;
    b[i] = y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  queue<P> q;
  q.push(make_pair(0, -1));
  while (!q.empty()) {
    P p = q.front();
    q.pop();
    int u = p.first;
    check[u] = 1;
    int c = p.second;
    int now = 0;
    for (auto v : G[u]) {
      if (check[v])
        continue;
      if (now == c)
        now++;
      q.push(make_pair(v, now));
      mp[make_pair(u,v)] = now;
      maxs(ans, now);
      now++;
    }
  }
  cout << min(n-1,ans+1) << endl;
  rep(i,n-1){
    cout<<mp[make_pair(a[i],b[i])]+1<<endl;
  }
  
  return 0;
}