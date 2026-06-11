#include <bits/stdc++.h> 
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  int U[H][W]={0},D[H][W]={0},L[H][W]={0},R[H][W]={0};
  char P[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>P[i][j];
    }
  }
  
  //LR
  for(int i=0;i<H;i++){
    int cur=1;
    for(int j=0;j<W;j++){
      if(P[i][j]=='#'){
        L[i][j]=0;
        cur=1;
      }
      else{
        L[i][j]=cur;
        cur++;
      }
    }
  }
  
  for(int i=0;i<H;i++){ 
    int cur=1;
    for(int j=W-1;j>=0;j--){
      if(P[i][j]=='#'){
        R[i][j]=0;
        cur=1;
      }
      else{
        R[i][j]=cur;
        cur++;
      }
    }        
  }
  
  //UD
  for(int i=0;i<W;i++){
    int cur=1;
    for(int j=0;j<H;j++){
      if(P[j][i]=='#'){
        U[j][i]=0;
        cur=1;
      }
      else{
        U[j][i]=cur;
        cur++;
      }
    }
  }
  
  for(int i=0;i<W;i++){
    int cur=1;
    for(int j=H-1;j>=0;j--){
      if(P[j][i]=='#'){
        D[j][i]=0;
        cur=1;
      }
      else{
        D[j][i]=cur;
        cur++;
      }
    }        
  }
  
  int cnt=0;
  int maxcnt=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cnt=U[i][j]+D[i][j]+R[i][j]+L[i][j]-3;
      maxcnt=max(maxcnt,cnt);
    }
  }
  cout<<maxcnt<<endl;

 return 0;
}