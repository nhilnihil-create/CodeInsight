#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> g(h);
  rep(i,h) cin >> g[i];


  vector<vector<int>> r(h,vector<int>(w,0)),
                      l(h,vector<int>(w,0)),
                      u(h,vector<int>(w,0)),
                      d(h,vector<int>(w,0));
  rep(i,h){
    int cnt = 0;
    for(int j = 0; j < w; j++){
      if(g[i][j]=='#') cnt = 0;
      else cnt++;
      l[i][j] = cnt;
    }
  }
  rep(i,h){
    int cnt = 0;
    for(int j = w-1; j >=0; j--){
      if(g[i][j]=='#') cnt = 0;
      else cnt++;
      r[i][j] = cnt;
    }
  }
  rep(j,w){
    int cnt = 0;
    for(int i = 0; i < h; i++){
      if(g[i][j]=='#') cnt = 0;
      else cnt++;
      u[i][j] = cnt;
    }
  }
  rep(j,w){
    int cnt = 0;
    for(int i = h-1; i >=0 ; i--){
      if(g[i][j]=='#') cnt = 0;
      else cnt++;
      d[i][j] = cnt;
    }
  }

  int ans = 0;
  rep(i,h)rep(j,w){
    ans = max(ans, r[i][j]+l[i][j]+u[i][j]+d[i][j]-3);
  }
  cout << ans << endl;

}
