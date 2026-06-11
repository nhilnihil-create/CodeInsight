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
  vector<int> v(n);
  rep(i, n) v[i] = i+1;
  vector<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];

  int a, b, cnt = 0;
  do {
    bool flagp = true, flagq = true;
    rep(i, n){
      if(v[i] != p[i]) flagp = false;
      if(v[i] != q[i]) flagq = false;
    }
    if(flagp) a = cnt;
    if(flagq) b = cnt;
    cnt++;
  } while(next_permutation(ALL(v)));

  int ans = abs(a-b);
  cout << ans << endl;
}
