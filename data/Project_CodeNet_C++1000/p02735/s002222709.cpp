#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int dx[] = {1,0};
int dy[] = {0,1};
 
int h,w;
vector<string> g;


int main(){
  cin >> h >> w;
  g.resize(h);
  rep(i,h) cin >> g[i];


  static int dp[100][100];
  rep(i,100){
    rep(j,100){
      dp[i][j] = inf;
    }
  }

  if(g[0][0] == '#') dp[0][0] = 1;
  else dp[0][0] = 0;
  
  rep(i,h){
    rep(j,w){
      rep(k,2){
        int ny = i + dy[k];
        int nx = j + dx[k];
        if(ny>h-1 || nx>w-1) continue;
        if(g[i][j] == '.' && g[ny][nx] == '#'){
          dp[ny][nx] = min(dp[ny][nx], dp[i][j]+1);
        }
        else dp[ny][nx] = min(dp[ny][nx], dp[i][j]);
      }
    }
  }
  cout << dp[h-1][w-1] << endl;
}
