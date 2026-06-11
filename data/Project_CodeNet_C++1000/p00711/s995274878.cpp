#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define loop(i,a,b) for(int i = a ; i < b ; i++)
#define rep(i,a) for(int i = 0 ; i < a ; i++) 

char maze[21][21];
int dx[4] = { 0, 0,-1, 1};
int dy[4] = {-1, 1, 0, 0};
int H,W;
bool inmaze(int x,int y){
  return (0<=x && x<H) && (0<=y && y<W);
}

int dfs(int x,int y){
  if(!inmaze(x,y))return 0;
  maze[x][y] = '#';
  int res = 1;
  rep(i,4){
    if(maze[x+dx[i]][y+dy[i]] == '.'){
      res += dfs(x+dx[i],y+dy[i]);
    }
  }
  return res;
}
int main(void){
  while(cin>>W>>H,H+W){
    int sx,sy;
    rep(i,H){
      string s;
      cin>>s;
      rep(j,W){
	maze[i][j] = s[j];
	if(s[j] == '@'){
	  sx = i;sy = j;
	}
      }
    }
    maze[sx][sy] = '.';
    cout<<dfs(sx,sy)<<endl;
  }
}