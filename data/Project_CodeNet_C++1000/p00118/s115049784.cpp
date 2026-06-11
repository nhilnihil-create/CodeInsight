#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
 
char array[101][101];
int H,W;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
int dfs(int Y, int X,char key){
  int nx,ny;
  array[Y][X]='.';
 
  for(int i=0;i<4;i++){
    nx=X+dx[i];
    ny=Y+dy[i];
    if(nx>=0 && nx<=W && ny>=0 && ny<=H && array[ny][nx]==key) dfs(ny,nx,key);
  }
 
}
 
 
int main(){
 
 
  while(1){
    cin>>H>>W;
    int cnt=0;
    if(H==0 && W==0) break;
    for(int i=0;i<H;i++)
      for(int j=0;j<W;j++)
    cin>>array[i][j];
    for(int i=0;i<H;i++)
      for(int j=0;j<W;j++)
    if(array[i][j]=='#' || array[i][j]=='*' || array[i][j]=='@'){
      dfs(i,j,array[i][j]);
      cnt++;
    }
    cout<<cnt<<endl;
  }
  return 0;
}