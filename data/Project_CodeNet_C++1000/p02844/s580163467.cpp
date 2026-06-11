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
  int n; cin >> n;
  string s; cin >> s;

  int ans = 0;

  rep(i, 10){
    rep(j, 10){
      rep(k, 10){
        int tgt = i, num = 0;
        rep(a, n){
          if(s[a] - '0' == tgt){
            if(num==0) {
              num++;
              tgt = j;
            } else if(num ==1){
              num++;
              tgt = k;
            } else {
              ans++;
              break;
            }
          }
        }
      }
    }
  }

  cout << ans << endl;
}
