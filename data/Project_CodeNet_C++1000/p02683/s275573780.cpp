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
static const ll INF = 1e18;

int main() {
  int n, m, x; cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int> (m));
  rep(i, n){
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }

  ll price = INF;

  rep(i, 1<<n){
    vector<int> understand(m, 0);
    ll sum = 0;
    rep(j, n){
      if((i>>j)&1){
        sum += c[j];
        rep(k, m){
          understand[k] += a[j][k];
        }
      }
    }

    bool flag = true;
    rep(i, m){
      if(understand[i] < x) flag = false;
    }
    if(flag) chmin(price, sum);
  }

  if(price == INF){
    cout << -1 << endl;
    return 0;
  }

  cout << price << endl;
  return 0;
}
