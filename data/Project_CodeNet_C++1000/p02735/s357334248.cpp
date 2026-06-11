#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int R, C;
char grid[105][105];
int memo[105][105];

bool inside(int r, int c){
  return 1<=r && r<=R && 1<=c && c<=C;
}

int dp(int r, int c){
  // base case
  if(r == R && c == C){
    return (grid[r][c] == '#');
  }

  // memo
  if(memo[r][c] != -1) return memo[r][c];

  // transisi
  int result = INT_MAX;
  int dx[] = {1, 0};
  int dy[] = {0, 1};
  for(int d=0; d<2; d++){
    int nxr = r+dx[d];
    int nxc = c+dy[d];

    if(!inside(nxr, nxc)) continue;
    if(grid[r][c] == '.') result = min(result, dp(nxr, nxc));
    else if(grid[r][c] == '#' && grid[nxr][nxc]=='#') result = min(result, dp(nxr,nxc));
    else if(grid[r][c] == '#' && grid[nxr][nxc]=='.') result = min(result, dp(nxr,nxc) + 1);									
  }

  return memo[r][c] = result;
}

int main(){

  cin >> R >> C;
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
      cin >> grid[i][j];
    }
  }

  memset(memo, -1, sizeof(memo));
  cout << dp(1,1) << endl;

} 