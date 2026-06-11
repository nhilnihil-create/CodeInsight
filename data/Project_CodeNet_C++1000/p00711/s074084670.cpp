#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fr first
#define sc second
typedef pair<int,int> pii;
typedef vector<int> vi;
const int INF = (1<<25);
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int w,h;
int sx,sy;
char room[20][21];
int res;

int dfs(int y,int x){
  room[y][x]='#';
  
  for(int i=0;i<4;i++){
    int ny=y+dy[i],nx=x+dx[i];
    if(0<=nx && nx<w && 0<=ny && ny<h && room[ny][nx]=='.'){
      res++;
      dfs(ny,nx);
    }
  }
}

int main(){
  while(cin>> w>> h,w){
    res=0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin>> room[i][j];
	if(room[i][j]=='@'){
	  sy=i; sx=j;
	}
      }
    }
    dfs(sy,sx);
    cout<< res+1<< endl;
  }
}