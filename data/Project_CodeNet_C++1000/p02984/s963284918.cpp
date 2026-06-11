# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mp make_pair
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];

  vector<ll> ans(n);

  ll sum = 0, fugou = 1;
  rep(i, n){
    sum += fugou * v[i];
    fugou *= -1;
  }

  ans[0] = sum;
  reps(i, n - 1){
      ans[i] = 2 * v[i-1] - ans[i-1];
  }

  rep(i, n){
    cout << ans[i] << endl;
  }
}
