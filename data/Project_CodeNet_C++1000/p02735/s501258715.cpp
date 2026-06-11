#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;cin >> H >> W;
  vector<string> S(H);
  for(int r=0;r<H;r++){
    cin >> S[r];
  }
  vector<vector<int>> M(H,vector<int>(W,0));
  if(S[0][0]=='#'){
    M[0][0]=1;
  }
  for(int j=1;j<W;j++){
    if(S[0][j-1]==S[0][j]){
      M[0][j] = M[0][j-1];
    }else{
      M[0][j] = M[0][j-1]+1;
    }
  }
  for(int i=1;i<H;i++){
    if(S[i][0]==S[i-1][0]){
      M[i][0] = M[i-1][0];
    }else{
      M[i][0] = M[i-1][0] + 1;
    }
    for(int j=1;j<W;j++){
      int DN = M[i-1][j];
      int RT = M[i][j-1];
      if(S[i][j]!=S[i-1][j]){
        DN ++;
      }
      if(S[i][j]!=S[i][j-1]){
        RT ++;
      }
      M[i][j] = min(DN,RT);
    }
  }
  int ans = M[H-1][W-1];
  if(S[H-1][W-1]=='#'){
    ans ++;
  }
  cout << ans/2 << endl;
}