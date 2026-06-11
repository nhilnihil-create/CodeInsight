#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

bool ok[2010][2010];
int U[2010][2010], D[2010][2010], L[2010][2010], R[2020][2010];

int main(int argc, char const *argv[]) {
  int h, w;
  cin >> h >> w;
  vector<string> G(h);
  rep(i, h) cin >> G[i];
  rep(i,h)rep(j,w){
    if (G[i][j] == '#') ok[i][j] = false;
  }
  //down
  rep(x,w){
    int cnt = 0;
    rep(y, h) {
      if (G[y][x]=='#') cnt = 0;
      else{
        cnt++;
        D[y][x] += cnt;
      }
    }
  }
  //up
  rep(x,w){
    int cnt = 0;
    for (int y = h - 1; y >= 0; y--) {
      if (G[y][x] == '#') cnt = 0;
      else {
        cnt++;
        U[y][x] += cnt;
      }
    }
  }
  
  //right
  rep(y,h) {
    int cnt = 0;
    rep(x,w) {
      if (G[y][x] == '#') cnt = 0;
      else {
        cnt++;
        R[y][x] += cnt;
      }
    }
  }

  // left
  rep(y, h) {
    int cnt = 0;
    for (int x = w - 1; x >= 0; x--) {
      if (G[y][x] == '#')
        cnt = 0;
      else {
        cnt++;
        L[y][x] += cnt;
      }
    }
  }

  //check
  /*rep(i,h){
    rep(j,w){
      printf("%d",L[i][j]);
    }
    cout << endl;
  }*/
  
  int ans = 0;
  rep(i, h) rep(j, w) chmax(ans, U[i][j] + D[i][j] + R[i][j] + L[i][j] - 3);
  cout << ans << endl;
  return 0;
}