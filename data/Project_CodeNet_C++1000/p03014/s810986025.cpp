#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  for(int i=0;i<H;i++){
    cin >> S[i];
  }
  vector<vector<int>> tate(H,vector<int>(W,0));
  vector<vector<int>> yoko(H,vector<int>(W,0));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(S[i][j]=='#'){
        continue;
      }
      if(tate[i][j]==0){
        int tcount=1;
        int tlim=0;
        for(int k=1;k<=H;k++){
          if(i+k>=H || S[i+k][j]=='#'){
            tlim=k;
            break;
          }
          tcount++;
        }
        for(int k=0;k<tlim;k++){
          tate[i+k][j]=tcount;
        }
      }
      if(yoko[i][j]==0){
        int ycount=1;
        int ylim=0;
        for(int k=1;k<=W;k++){
          if(j+k>=W || S[i][j+k]=='#'){
            ylim=k;
            break;
          }
          ycount++;
        }
        for(int k=0;k<ylim;k++){
          yoko[i][j+k]=ycount;
        }
      }
    }
  }
  int ans=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      tate[i][j]+=yoko[i][j];
      ans=max(ans,tate[i][j]);
    }
  }
  cout << ans-1 << endl;
}