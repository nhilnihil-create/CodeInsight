#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  string grid[h];
  for(int i=0;i<h;i++){
    cin>>grid[i];
  }
  int vec[h][w]={};
  int vecb[h][w]={};
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(grid[i][j]=='#')continue;
      if(j>0&&grid[i][j-1]=='.'){
        vec[i][j]=vec[i][j-1];
        continue;
      }
      int x=0;
      int now=j;
      while(now<w&&grid[i][now]=='.'){
        x++;
        now++;
      }
      vec[i][j]=x;
    }
  }
  
  
  for(int j=0;j<w;j++){
    for(int i=0;i<h;i++){
      if(grid[i][j]=='#')continue;
      if(i>0&&grid[i-1][j]=='.'){
        vecb[i][j]=vecb[i-1][j];
        continue;
      }
      int x=0;
      int now=i;
      while(now<h&&grid[now][j]=='.'){
        x++;
        now++;
      }
      vecb[i][j]=x;
    }
  }
  
  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      ans=max(ans,vec[i][j]+vecb[i][j]-1);
    }
  }
  cout<<ans<<endl;
}