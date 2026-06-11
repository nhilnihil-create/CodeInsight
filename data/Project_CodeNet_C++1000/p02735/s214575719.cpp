#include<iostream>

using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  char m[H][W];
  int dp[H][W];
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> m[i][j];
      dp[i][j] = 0;
    }
  }

  if(m[0][0]=='#'){
    dp[0][0] = 1;
  }

  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      int w=100000, h=100000;
      if(i==0 && j==0){
        continue;
      }

      if(0 < j){
        if(m[i][j]==m[i][j-1]){
          w = dp[i][j-1];
        }else{
          w = dp[i][j-1] + 1;
        }
      }
      
      if(0 < i){
        if(m[i][j]==m[i-1][j]){
          h = dp[i-1][j];
        }else{
          h = dp[i-1][j] + 1;
        }
      }

      dp[i][j] = min(h,w);
    }
  }

  if(m[H-1][W-1]=='#'){
    dp[H-1][W-1] += 1;
  }

  printf("%d\n", dp[H-1][W-1] / 2);
}
