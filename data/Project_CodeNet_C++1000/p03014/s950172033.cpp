#include <bits/stdc++.h>
using namespace std ;
 
int main(){
    int H,W;cin>>H>>W;
    char s[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++)
        cin >> s[i][j];
    }
    
    int L[H][W],R[H][W],U[H][W],D[H][W];

    for(int i=0;i<H;i++){
        if(s[i][0]=='#') L[i][0]=0;
        else L[i][0]=1;
        if(s[i][W-1]=='#') R[i][W-1]=0;
        else R[i][W-1]=1;
    }
    for(int i=0;i<W;i++){
        if(s[0][i]=='#') U[0][i]=0;
        else U[0][i]=1;
        if(s[H-1][i]=='#') D[H-1][i]=0;
        else D[H-1][i]=1;

    }

    for(int i=0;i<H;i++){
        for(int j=1;j<W;j++)
            if(s[i][j]=='.') L[i][j]=L[i][j-1]+1;
            else L[i][j]=0;     
    }
      
    for(int i=1;i<H;i++){
        for(int j=0;j<W;j++){
            if(s[i][j]=='.') U[i][j]=U[i-1][j]+1;
            else U[i][j]=0;
        }
    }
  for(int i=H-2;i>=0;i--){
    for(int j=W-1;j>=0;j--){
      if(s[i][j]=='.')D[i][j]=D[i+1][j]+1;
      else D[i][j]=0;
    }
  }
  

    for(int i=H-1;i>=0;i--){
        for(int j=W-2;j>=0;j--){
            if(s[i][j]=='.') R[i][j]=R[i][j+1]+1;
            else R[i][j]=0;
        }
    }

    for(int i=H-2;i>=0;i--){
        for(int j=W-1;j>=0;j--){
            if(s[i][j]=='.') D[i][j]=D[i+1][j]+1;
            else D[i][j]=0;
        }
    }

    int Max=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++)
        Max=max(Max,L[i][j]+R[i][j]+U[i][j]+D[i][j]-3);
    }
  cout <<Max<<endl;

}