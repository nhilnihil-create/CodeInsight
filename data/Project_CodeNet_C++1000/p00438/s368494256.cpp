#include<cstdio>
#include<iostream>
using namespace std;

int w,h,n,sx,sy,cnt;
int mas[20][20];
int dx[2]={1,0};
int dy[2]={0,1};

void Set(void);
void fbs(int x,int y);

main(){
  while(1){
    cin >> w >> h;
    if(w==0 && h==0){
      break;
    }
    Set();
    cin >> n;
    for(int i=0;i<n;i++){
      int x,y;
      cin >> x >> y;
      mas[y][x]=1;
    }
    fbs(1,1);
    cout << cnt << endl;
  }
}

void Set(void){
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      mas[i][j]=0;
    }
  }
  cnt=0;
}

void fbs(int x,int y){
  if(x==w && y==h){
    cnt++;
  }
  else{
    for(int i=0;i<2;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx<=w && ny<=h && mas[ny][nx]==0){
	fbs(nx,ny);
      }
    }
  }
}