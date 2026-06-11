#include<bits/stdc++.h>
using namespace std;
#define int long long 

char s[110][110];
int dp[110][110];

const int inf = 1000;

signed main(void){
  int h,w; cin >> h >> w;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){ 
      cin >> s[i][j];
      dp[i][j] = inf;
    }
  }
  
  dp[0][0] = 0;
  
  for(int x = 0; x < h; x++){
    for(int y = 0; y < w; y++){ 
      
      if( x+1 < h ){
        
        int c = (s[x+1][y] == '#' && s[x][y] == '.');
        
        dp[x+1][y] = min(dp[x+1][y],dp[x][y]+c);
      }
      
      if( y+1 < w ){ 
        
        int d = (s[x][y+1] == '#' && s[x][y] == '.');
        
        dp[x][y+1] = min(dp[x][y+1],dp[x][y]+d);
        
      }
    }
  }
  
  int r = ( s[0][0] == '#' );
  
  cout << dp[h-1][w-1]+r << endl;
  
  return 0;
} 
    