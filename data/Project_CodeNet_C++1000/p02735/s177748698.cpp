#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dp[150][150];
bool seen[150][150];
vector<string> fi;
int H,W;
int f(int x, int y){
  if(seen[x][y]) return dp[x][y];
  seen[x][y]=true;
  int a=0,b=0;
  if(x==H-1){
    if(fi[x][y]!=fi[x][y+1]) dp[x][y]=f(x,y+1)+1;
    else dp[x][y]=f(x,y+1);
  }
  else if(y==W-1){
    if(fi[x][y]!=fi[x+1][y])  dp[x][y]=f(x+1,y)+1;
    else dp[x][y]=f(x+1,y);
  }
  else {
    if(fi[x][y]!=fi[x][y+1]) a=f(x,y+1)+1;
    else a=f(x,y+1);
    if(fi[x][y]!=fi[x+1][y])  b=f(x+1,y)+1;
    else b=f(x+1,y);
    dp[x][y]=min(a,b);
  }
  return dp[x][y];
}
    

int main() {
  cin>>H>>W;
  fi.resize(H);
  rep(i,H) cin>>fi[i];
  dp[H-1][W-1]=0;
  seen[H-1][W-1]=true;
  int ans=f(0,0);
  if(ans%2==1) ans=(ans+1)/2;
  else {
    if(fi[0][0]=='#') ans = (ans+1)/2+1;
    else ans = (ans+1)/2;
  }
  cout<<ans<<endl;
}