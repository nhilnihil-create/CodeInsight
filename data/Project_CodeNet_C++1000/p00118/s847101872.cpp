#include<iostream>
using namespace std;
int dfs(int y,int x);
int h,w;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char flu;
char ma[111][111];
int main(){
  while(1){
    int cou=0;
    cin>>h>>w;
    if(h==0 && w==0) break;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin>>ma[i][j];
      }
    }
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	if(ma[i][j]=='#' || ma[i][j]=='*' || ma[i][j]=='@'){
	  flu=ma[i][j];
	  dfs(i,j);
	  cou++;
	}
      }
    }
    cout<<cou<<endl;
  }
}
int dfs(int y,int x){
  ma[y][x]='.';
  for(int i=0;i<4;i++){
    int ny=y+dy[i];
    int nx=x+dx[i];
    if(0<=nx && nx<w && 0<=ny && ny<h && ma[ny][nx]==flu){
      dfs(ny,nx);
    }
  }
}