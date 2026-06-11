#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
  int H, W;
  cin >> H >> W;
  
  int left[H][W], right[H][W], up[H][W], down[H][W];
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      left[i][j] = 0;
      right[i][j] = 0;
      up[i][j] = 0;
      down[i][j] = 0;
    }
  }
  
  vector<string> S(H);
  for (int i=0; i<H; i++) cin >> S[i];
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(S[i][j]=='.'){
      	if(j==0){
          left[i][j] = 1;
        }else{
          left[i][j] = left[i][j-1] + 1;
        }
      }
    }
  }
  
   for(int i=0; i<H; i++){
    for(int j=W-1; j>=0; j--){
      if(S[i][j]=='.'){
      	if(j==W-1){
          right[i][j] = 1;
        }else{
          right[i][j] = right[i][j+1] + 1;
        }
      }
   
    }
   }
  
  
   for(int i=0; i<W; i++){
    for(int j=H-1; j>=0; j--){
      if(S[j][i]=='.'){
        if(j==H-1){
          down[j][i] = 1;
        }else{
          down[j][i] = down[j+1][i] + 1;
        }
      }
      
    }
  }
  
  
  for(int i=0; i<W; i++){
    for(int j=0; j<H; j++){
      if(S[j][i]=='.'){
        if(j==0){
          up[j][i] = 1;
        }else{
          up[j][i] = up[j-1][i] + 1;
        }
      }
      
    }
  }
  
  
  
  int res = 0;
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(S[i][j]=='#') continue;
      res = max(res, left[i][j]+right[i][j]+up[i][j]+down[i][j]-3);
    }
  }
  
  cout << res << endl;
 
  return 0;
}