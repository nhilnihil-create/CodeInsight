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
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  sort(ALL(s));
  vector<pair<int, string>> v;
  int cnt = 0;
  rep(i, n-1){
    ++cnt;
    if(s[i]!=s[i+1]){
      v.pb(make_pair(-cnt, s[i]));
      cnt = 0;
    }
  }
  ++cnt;
  v.pb(make_pair(-cnt, s[n-1]));
  sort(ALL(v));

  int maxi = v[0].first;
  rep(i, v.size()){
    if(v[i].first != maxi) return 0;
    cout << v[i].second << endl;
  }
  return 0;
}
