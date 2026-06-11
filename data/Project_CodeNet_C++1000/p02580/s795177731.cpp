# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define P pair<int, int>
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
static const ll INF = 1e17;

int main(){
  optimize_cin();
  int h, w, m; cin >> h >> w >> m;
  vector<int> countx(h, 0), county(w, 0);
  set<P> s;
  rep(i, m){
    int x, y; cin >> x >> y;
    --x; --y;
    ++countx[x];
    ++county[y];
    s.emplace(x, y);
  }

  int maxx = 0, maxy = 0;
  rep(i, h) chmax(maxx, countx[i]);
  rep(i, w) chmax(maxy, county[i]);

  ll ans = maxx + maxy;
  vector<int> goodx, goody;
  rep(i, h) if(countx[i]==maxx) goodx.pb(i);
  rep(i, w) if(county[i]==maxy) goody.pb(i);

  for(auto x : goodx){
    for(auto y : goody){
      if(s.count(P(x, y))) continue;
      cout << ans << endl;
      return 0;
    }
  }

  cout << ans - 1 << endl;
  return 0;
}
