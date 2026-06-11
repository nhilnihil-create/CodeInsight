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
# define mp make_pair
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll lmax(ll a, ll b){
  if(a>= b) return a; else return b;
}

ll lmin(ll a, ll b){
  if(a>= b) return b; else return a;
}

int main() {
  int n; cin >> n;
  vector<ll> a(n+1), b(n);
  rep(i, n+1) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll ans = 0;
  rep(i, n){
    ans += lmin(a[i], b[i]);
    if(b[i] > a[i]){
      b[i] -= a[i];
      ans += lmin(a[i+1], b[i]);
      a[i+1] = lmax(a[i+1] - b[i], 0);
    }
  }

  cout << ans << endl;
}
