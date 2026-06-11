#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int h,w; cin >> h >> w;
  vector<string> s(h); rep(i,h) cin >> s[i];
  vector<vi> l(h,vi(w)), r(h,vi(w)), u(h,vi(w)), d(h,vi(w));
  rep(i,h){
    rep(j,w){
      if(s[i][j] == '#') l[i][j] = 0;
      else{
        if(!j) l[i][j] = 1;
        else l[i][j] = l[i][j-1]+1;
      }
    }
  }
  rep(i,h){
    for(int j = w-1; 0 <= j; j--){
      if(s[i][j] == '#') r[i][j] = 0;
      else{
        if(j == w-1) r[i][j] = 1;
        else r[i][j] = r[i][j+1]+1;
      }
    }
  }
  rep(j,w){
    rep(i,h){
      if(s[i][j] == '#') u[i][j] = 0;
      else{
        if(!i) u[i][j] = 1;
        else u[i][j] = u[i-1][j]+1;
      }
    }
  }
  rep(j,w){
    for(int i = h-1; 0 <= i; i--){
      if(s[i][j] == '#') d[i][j] = 0;
      else{
        if(i == h-1) d[i][j] = 1;
        else d[i][j] = d[i+1][j]+1;
      }
    }
  }
  int ans = 0;
  rep(i,h) rep(j,w) chmax(ans,l[i][j]+r[i][j]+d[i][j]+u[i][j]-3);
  cout << ans;
  cout << "\n";
  return 0;
}
