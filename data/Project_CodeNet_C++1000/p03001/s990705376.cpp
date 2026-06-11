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

int main() {
  double w, h, x, y; cin >> w >> h >> x >> y;

  double ans = w / 2;
  ans *= h;
  int subans = 0;
  if(w / 2 == x && h / 2 == y) subans = 1;

  cout << ans << endl;
  cout << subans << endl;
}
