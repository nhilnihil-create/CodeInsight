# include <bits/stdc++.h>
# define rep(i, n) for(ll i = 0; i < (n); ++i)
# define reps(i, n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(ll i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(ll i=((int)(n)); i>0; --i)
# define ll long long
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define P pair<int, int>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll lmax(ll a, ll b){if(a>= b) return a;return b;}
ll lmin(ll a, ll b){if(a>= b) return b;return a;}

int n, m, q;
vector<int> a, b, c, d;
ll ans = 0;

void dfs(vector<int> v){
  if(v.size()==n+1){
    ll sum = 0;
    rep(i, q){
      if(v[b[i]] - v[a[i]]==c[i]) sum += d[i];
    }
    chmax(ans, sum);
    return;
  }

  v.pb(v.back());
  while(v.back()<=m){
    dfs(v);
    ++(v.back());
  }
}

int main() {
  cin >> n >> m >> q;
  a.resize(q);
  b.resize(q);
  c.resize(q);
  d.resize(q);
  rep(i, q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i]; --b[i];
  }

  vector<int> v(1, 1);
  dfs(v);
  cout << ans << endl;
}
