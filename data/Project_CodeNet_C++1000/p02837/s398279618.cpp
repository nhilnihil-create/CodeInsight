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

int main() {
  int n; cin >> n;
  vector<vector<P>> v(n, vector<P>(0));
  vector<int> u(n);
  rep(i, n){
    int a; cin >> a;
    u[i] = a;
    v[i].resize(a);
    rep(j, a){
      int x, y; cin >> x >> y;
      --x;
      v[i][j] = make_pair(x, y);
    }
  }

  int ans = 0;
  rep(s, 1<<n){
    bool flag = true;
    rep(i, n){
      if((s>>i)&1){
        rep(j, u[i]){
          if(((s>>(v[i][j].first))&1) != v[i][j].second){
            flag = false;
          }
        }
      }
    }
    if(flag) chmax(ans, __builtin_popcount(s));
  }

  cout << ans << endl;
}
