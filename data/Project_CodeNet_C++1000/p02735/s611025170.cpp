# include <iostream>
# include <climits>
# include <cstring>
using namespace std;
int dp[105][105];
char grid[105][105];
int R, C;
int dx[] = {1,0};
int dy[] = {0,1};
bool inside(int r, int c){
  return 1<=r && r<=R && 1<=c && c<=C;
}

int solve(int r,int c){
  if(r == R && c == C) return grid[r][c] == '#';
  if(dp[r][c] != -1) return dp[r][c];

  int ans = INT_MAX;
  for(int d=0; d<2; d++){
    int nxr = r+dx[d];
    int nxc = c+dy[d];
    if(!inside(nxr, nxc)) continue;
    if(grid[r][c] == '.') ans = min(ans, solve(nxr, nxc));
    else if(grid[r][c] == '#' && grid[nxr][nxc] == '#') ans = min(ans, solve(nxr, nxc));
    else ans = min(ans, solve(nxr, nxc)+1);
  }
  return dp[r][c] = ans;
}

int main(){
  memset(dp, -1, sizeof(dp));
  cin >> R >> C;
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++)
      cin >> grid[i][j];
  }

  cout << solve(1,1) << endl;
  return 0;
}