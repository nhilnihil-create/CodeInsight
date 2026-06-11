#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int W,H,nx,ny;
char kaju[111][111];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
char fulu;
int hata=0;

int fact(int x,int y){
  kaju[x][y]='.';
  for(int i=0;i<4;i++){
    nx=x+dx[i];
    ny=y+dy[i];
    if(0 <= nx && nx < H && 0 <= ny && ny < W && kaju[nx][ny] == fulu){
      fact(nx,ny);
    }
  }
}


int main(){
  while(1){
    hata=0;
    cin >> H >> W;
    if(H == 0 && W == 0)break;
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
	cin >> kaju[i][j];
      }
    }
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
	if(kaju[i][j]!='.'){
	  fulu=kaju[i][j];
	  fact(i,j);
	  hata++;
	}
      }
    }
    cout << hata << endl;
  }
}

 