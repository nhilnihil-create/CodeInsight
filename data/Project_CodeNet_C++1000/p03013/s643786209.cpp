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
# define x first
# define y second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

static const ll mod = 1000000007LL;

int dp[100010];

int main() {
  int n, m; cin >> n >> m;
  vector<bool> a(n + 1, true);
  rep(i, n) {
    int x; cin >> x;
    a[x] = false;
  }

  dp[0] = 1;
  if(!a[1] && !a[2]) {
    cout << 0 << endl;
    return 0;
  }
  rep(i, n + 1){
    if(a[i+1]) dp[i+1] = (dp[i+1] + dp[i]) % mod;
    if(a[i+2]) dp[i+2] = (dp[i+2] + dp[i]) % mod;
  }

  cout << dp[n] << endl;
}
