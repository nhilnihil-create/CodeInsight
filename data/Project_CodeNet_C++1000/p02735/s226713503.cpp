#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<char>> a(100,vector<char>(100));
int dp[100][100];
int fnc(int x, int y) {
  if(x==0&&y==0) {
    if(a[0][0]=='#') return 1;
    return 0;
  }
  int xx=300, yy=300;
  if(x>0) xx=dp[x-1][y];
  if(y>0) yy=dp[x][y-1];
  if(a[x][y]=='#') {
    if(x>0&&a[x-1][y]=='.') xx++;
    if(y>0&&a[x][y-1]=='.') yy++;
  }
  return min(xx,yy);
  }

int main() {
  int h, w;
  cin >> h >> w;
  rep(i,h) {
    rep(j,w) {
      cin >> a[i][j];
      dp[i][j]=fnc(i,j);
    }
  }
  
  cout << dp[h-1][w-1] << endl;
  return 0;
}