#include<queue>
#include<stdio.h>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define SIZE 1010
using namespace std;

typedef pair<int,int> P;

char mass[SIZE][SIZE];
int  data[SIZE][SIZE];
int  dx[4]={1,0,-1,0};
int  dy[4]={0,1,0,-1};
int  sx,sy,gx,gy;
int  h,w,n;
int  k;
int  sum=0;

int bfs();

int main(){

  int i,j;

  cin>>h>>w>>n;

  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cin>>mass[i][j];
    }
  }

  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(mass[i][j]=='S'){
	sx=j;
	sy=i;
	break;
      }
    }
  }

  for(k=1;k<=n;k++){
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if(mass[i][j]-'0'==k){
	  gx=j;
	  gy=i;
	}
      }
    }
    sum+=bfs();
    sx=gx;
    sy=gy;
  }                      
  
  cout<<sum<<endl;
  
  return 0;
}
int bfs(){

  int i,j;
  queue<P> que;

  memset(data,-1,sizeof(data));

  que.push(P(sy,sx));
  data[sy][sx]=0;

  while(!que.empty()){

    P p=que.front();
    que.pop();

    if(p.first==gy && p.second==gx){
      return data[p.first][p.second];
    }

    for(i=0;i<4;i++){
      int nx=p.second+dx[i];
      int ny=p.first+dy[i];

      if(nx>=0 && nx<w && ny>=0 && ny<h && mass[ny][nx]!='X' && data[ny][nx]==-1){
	que.push(P(ny,nx));
	data[ny][nx]=data[p.first][p.second]+1;
    }
   }
  }
 return 0;
}