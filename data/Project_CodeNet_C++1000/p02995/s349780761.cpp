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

ll gcd (ll x, ll y) {
  if(x==0) return y;
  return gcd(y%x,x);
}

int main() {
  ll a, b, c, d; cin >> a >> b >> c >> d;

  ll lcm = c / gcd(c, d) * d;
  ll ans = b - a + 1 - (b/c - (a-1)/c + b/d - (a-1)/d - b/lcm + (a-1)/lcm);
  cout << ans << endl;
}
