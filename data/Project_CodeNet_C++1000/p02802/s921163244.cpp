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
  int n, m; cin >> n >> m;
  vector<ll> p(m);
  vector<string> s(m);
  rep(i, m){
    cin >> p[i] >> s[i];
    --p[i];
  }

  ll acs = 0, pena = 0;
  vector<bool> v(n, false);
  vector<int> cnt(n, 0);
  rep(i, m){
    if(v[p[i]]) continue;
    if(s[i][0] == 'A'){
      ++acs;
      v[p[i]] = true;
      pena += cnt[p[i]];
    } else {
      ++cnt[p[i]];
    }
  }

  cout << acs << endl;
  cout << pena << endl;
}
