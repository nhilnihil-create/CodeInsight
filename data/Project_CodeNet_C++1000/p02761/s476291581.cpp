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

int digit(int n){
  n /= 10;
  int res = 1;
  while(n){
    res++;
    n/=10;
  }

  return res;
}

int ketame(int x, int n, int y){
  rep(i, y - n){
    x /= 10;
  }

  return (x % 10);
}

int main() {
  int n, m; cin >> n >> m;
  vector<int> s(m), c(m);
  rep(i, m){
    cin >> s[i] >> c[i];
  }

  rep(i, 1000){
    if(n != digit(i)) continue;
    bool flag = true;
    rep(j, m){
      if(ketame(i, s[j], n) != c[j]) flag = false;
    }
    if(flag){
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
