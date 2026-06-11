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
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> ans(n+1, 0);
  int m = 0;
  vector<int> b;
  rreps(i, n){
    int sum = 0;
    for(int j = i * 2; j <= n; j += i){
      sum += ans[j];
    }
    if(sum %2 != a[i-1]) {
      ans[i] = 1;
      ++m;
      b.pb(i);
    }
  }

  cout << m << endl;
  rep(i, m) cout << b[i] << endl;
}
