#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define per(i,n) for(ll i = n-1; i >= 0; i--)
#define REP(i,n) for(ll i = 1; i < n; i++)
#define PER(i,n) for(ll i = n; i >= 1; i--)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vs = vector<string>;
using vb = vector<bool>;
using vc = vector<char>;
using vcc = vector<vc>;
using vP = vector<P>;
using vPP = vector<vP>;
using vPl = vector<Pl>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void dfs(int v, int tot, vi &ans, vi &cnt, const vii &g, vb &seen) {
  seen[v] = true;
  ans[v] = cnt[v] + tot;
  for(int nv : g[v]) {
    if(seen[nv]) continue;
    dfs(nv, ans[v], ans, cnt, g, seen);
  }
}

int main(){
  int n, q;
  cin >> n >> q;
  vii g(n);
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vi cnt(n);
  rep(i,q) {
    int p, x;
    cin >> p >> x;
    p--;
    cnt[p] += x;
  }
  vb seen(n);
  vi ans(n);
  dfs(0, 0, ans, cnt, g, seen);
  rep(i,n) cout << ans[i] << ' ';
}