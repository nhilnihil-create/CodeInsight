#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<int>> maze(h,vector<int>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      char c;
      cin >> c;
      if(c == '.'){
        maze[i][j] = 1;
      }else{
        maze[i][j] = 0;
      }
    }
  }
  
  vector<vector<int>> right(h,vector<int>(w));
  vector<vector<int>> left(h,vector<int>(w));
  vector<vector<int>> up(h,vector<int>(w));
  vector<vector<int>> down(h,vector<int>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(maze[i][j] == 0) continue;
      if(j==0){
        left[i][j] = 1;
      }else{
        left[i][j] = left[i][j-1] + 1;
      }
      if(i==0){
        up[i][j] = 1;
      }else{
        up[i][j] = up[i-1][j] + 1;
      }
    }
  }
  
  for(int i=h-1;i>=0;i--){
    for(int j=w-1;j>=0;j--){
      if(maze[i][j] == 0) continue;
      if(j==w-1){
        right[i][j] = 1;
      }else{
        right[i][j] = right[i][j+1] + 1;
      }
      if(i==h-1){
        down[i][j] = 1;
      }else{
        down[i][j] = down[i+1][j] + 1;
      }
    }
  }
  
  //vector<vector<int>> dp(h,vector<int>(w));
  int ans=0;
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int light=right[i][j]+left[i][j]+up[i][j]+down[i][j]-3;
      if(ans < light){
        ans = light;
      }
    }
  }
  
  cout << ans << endl;
  
  return(0);
}