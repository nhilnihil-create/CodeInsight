#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }

int main(void){
  int h,w; cin >> h >> w;
  char s[h][w];
  rep(i,h){
    rep(j,w){
      cin >> s[i][j];
    }
  }
  int l[h][w],r[h][w],u[h][w],d[h][w];
  rep(i,h){
    rep(j,w){
      if(s[i][j] == '#') l[i][j] = 0;
      else if(j == 0) l[i][j] = 1;
      else l[i][j] = l[i][j-1]+1;
    }
  }
  rep(i,h){
    for(int j = w-1; j >= 0; j--){
      if(s[i][j] == '#') r[i][j] = 0;
      else if(j == w-1) r[i][j] = 1;
      else r[i][j] =r[i][j+1]+1;
    }
  }
  rep(i,h){
    rep(j,w){
      if(s[i][j] == '#') u[i][j] = 0;
      else if(i == 0) u[i][j] = 1;
      else u[i][j] = u[i-1][j]+1;
    }
  }
  rep(j,w){
    for(int i = h-1; i >= 0; i--){
      if(s[i][j] == '#') d[i][j] = 0;
      else if(i == h-1) d[i][j] = 1;
      else d[i][j] = d[i+1][j]+1;
    }
  }
  int ans = 0;
  rep(i,h){
    rep(j,w){
      int count = l[i][j] + r[i][j] + u[i][j] + d[i][j] -3;
      ans = max(ans,count);
    }
  }
  cout << ans << endl;
  return 0;
}
