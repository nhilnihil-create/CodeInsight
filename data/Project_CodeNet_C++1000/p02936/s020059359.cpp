#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

vector<int> G[200010];
vector<ll> ans(200010,0);

void dfs(int v, int p) {
  if(p!=-1) ans[v] += ans[p];
  for (auto nx : G[v]) {
    if (nx == p) continue;
    dfs(nx, v);
  }
}

int main(int argc, char const* argv[]) {
  int n, q;
  cin >> n >> q;
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--, b--;
    G[a].pb(b), G[b].pb(a);
  }
  rep(i,q) {
    int p,x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }
  dfs(0, -1);
  rep(i, n) cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  return 0;
}