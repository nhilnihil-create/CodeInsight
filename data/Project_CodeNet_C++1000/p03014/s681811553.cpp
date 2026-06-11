#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;cin>>H>>W;
  vector<string>S(H);
  for(int i=0; i<H; i++)cin>>S[i];

  int L[H][W], R[H][W], U[H][W], D[H][W];

  for(int i=0, I=H-1; i<H; i++, I--){
    for(int j=0, J=W-1; j<W; j++, J--){
      {//L
        if(S[i][j]=='.'){
          if(j==0)L[i][j] = 1;
          else L[i][j] = L[i][j-1] +1;
        }else{
          L[i][j] = 0;
        }
      }
      {//R
        if(S[i][J]=='.'){
          if(J==W-1)R[i][J] = 1;
          else R[i][J] = R[i][J+1] +1;
        }else{
          R[i][J] = 0;
        }
      }
      {//U
        if(S[i][j]=='.'){
          if(i==0)U[i][j] = 1;
          else U[i][j] = U[i-1][j] +1;
        }else{
          U[i][j] = 0;
        }
      }
      {//D
        if(S[I][j]=='.'){
          if(I==H-1)D[I][j] = 1;
          else D[I][j] = D[I+1][j] +1;
        }else{
          D[I][j] = 0;
        }
      }
    }
  }

  int ans = 0;
  for(int i=0; i<H; i++)for(int j=0; j<W; j++){
    ans = max(ans, L[i][j]+R[i][j]+U[i][j]+D[i][j]-3);
  }
  cout<<ans<<endl;
}