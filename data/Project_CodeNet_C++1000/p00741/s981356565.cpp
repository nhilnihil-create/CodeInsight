#include <iostream>
#include <cstdio>
#include <stack>
#include <utility>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define FST first
#define SEC second

typedef pair <int,int> pxy;

int dfs(int map[][50],int w,int h){
  int dd[10]={0, 1, 1, 1, 0, -1, -1, -1, 0, 1};
  stack <pxy> s;
  int num=0;
  rep(y,h){
    rep(x,w){
      if(map[x][y]==1){
	s.push(pxy(x,y));
	while(!s.empty()){
	  int cx=s.top().FST,cy=s.top().SEC;
	  s.pop();
	  map[cx][cy]=0;
	  rep(r,8){
	    int nx=cx+dd[r],ny=cy+dd[r+2];
	    if(nx<0||w<=nx||ny<0||h<=ny||map[nx][ny]==0) continue;
	    s.push(pxy(nx,ny));
	  }
	}
	num++;
      }
    }
  }
  return num;
}

int main() {
  for(;;){
    int w,h,x,y;
    scanf("%d %d",&w,&h);
    int map[50][50];
    if(w==0&&h==0) break;
    rep(i,h){
      rep(j,w){
	cin >> map[j][i];
      }
    }
    cout << dfs(map,w,h) << endl;
  } 
}