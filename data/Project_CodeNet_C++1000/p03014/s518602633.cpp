#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;

  int L[2010][2010], R[2010][2010], D[2010][2010], U[2010][2010];
  bool grid[2010][2010];
  for(int i=0; i<H; i++){
for(int j=0; j<W; j++){
char a;
  cin>>a;
  if(a=='.') grid[i][j]=true;
  else grid[i][j]=false;

  }
  }

  
  for(int i=0; i<H; i++){
    int cur=0;
    for(int j=0; j<W; j++){
if(grid[i][j]==false) cur=0;
     else cur++;
      L[i][j]=cur;
    }
  }
      for(int i=0; i<H; i++){
    int cur=0;
    for(int j=W; j>-1; j--){
if(grid[i][j]==false) cur=0;
     else cur++;
      R[i][j]=cur;
    }
      }
        for(int j=0; j<W; j++){
    int cur=0;
    for(int i=0; i<H; i++){
if(grid[i][j]==false) cur=0;
     else cur++;
      U[i][j]=cur;
    }  
        }
          
     for(int j=0; j<W; j++){
    int cur=0;
    for(int i=H; i>-1; i--){
if(grid[i][j]==false) cur=0;
     else cur++;
      D[i][j]=cur;
      }
     }
  int res=0;
       for(int i=0; i<H; i++){
for(int j=0; j<W; j++){
      res=max(res,D[i][j]+U[i][j]+R[i][j]+L[i][j]);
}
       }
  
    cout<<res-3<<endl;
}
