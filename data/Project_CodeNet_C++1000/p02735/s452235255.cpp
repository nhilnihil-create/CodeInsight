#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W; cin >> H >> W;
  vector<string> s(H);
  for(int i=0; i<H; i++) cin >> s[i];
  
  vector<vector<int>> flip(H,vector<int>(W,1000000));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(i==0&&j==0){
        if(s[i][j]=='#') flip[i][j]=1;
        else flip[i][j]=0;
      }else if(i==0){
        if(s[i][j]=='#'&&s[i][j-1]=='.'){
          flip[i][j]=flip[i][j-1]+1;
        }else{
          flip[i][j]=flip[i][j-1];
        }
      }else if(j==0){
        if(s[i][j]=='#'&&s[i-1][j]=='.'){
          flip[i][j]=flip[i-1][j]+1;
        }else{
          flip[i][j]=flip[i-1][j];
        }
      }else{
        if(s[i][j]=='#'&&s[i][j-1]=='.'){
          flip[i][j]=flip[i][j-1]+1;
        }else{
          flip[i][j]=flip[i][j-1];
        }
        if(s[i][j]=='#'&&s[i-1][j]=='.'){
          flip[i][j]=min(flip[i][j],flip[i-1][j]+1);
        }else{
          flip[i][j]=min(flip[i][j],flip[i-1][j]);
        }
      }
    }
  }
  cout << flip[H-1][W-1] << endl;
}