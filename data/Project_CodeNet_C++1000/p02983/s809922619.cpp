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

int main() {
  ll l, r; cin >> l >> r;

  if(r - l > 2019) {
    cout << 0 << endl;
    return 0;
  } else {
    ll sa = r - l;
    l %= 2019;
    r = l + sa;
    int ans = 2019;
    for(int i = l; i < r; i++){
      for(int j = i + 1; j <= r; j++){
        ans = min(ans, (i * j)%2019);
      }
    }
    cout << ans << endl;
  }
}
