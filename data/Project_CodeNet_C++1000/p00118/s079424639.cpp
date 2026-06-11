#include<iostream>
using namespace std;
char fg[101][101];
int H,W;
int a[4]={-1,0,0,1};
int b[4]={0,-1,1,0};
char nowfruit;
int cnt=0;
void func(int x,int y);
main(){
  while(1){
    cnt=0;
  cin>> H>> W;
  if(H==0&&W==0) break;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>> fg[i][j];
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(fg[i][j]!='.'){
	nowfruit=fg[i][j];
	func(i,j);
	cnt++;
      }
    }
  }
  cout<< cnt<< endl;
  }
}
void func(int x,int y){
  fg[x][y]='.';
  for(int vh=0;vh<4;vh++){
    int nx=x+a[vh];
    int ny=y+b[vh];
    if(nx>=0 && nx<H && ny>=0 && ny<W && fg[nx][ny]==nowfruit){
      func(nx,ny);
    }
  }
}