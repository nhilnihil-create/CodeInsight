/* competitive programming circle traP */
/* template */
#include <stdio.h>
#include <queue>
using namespace std;

int h,w,n;
int px[11];
int py[11];
int mp[1000][1000];
bool used[1000][1000];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int bfs(int sy,int sx,int gy,int gx){
  for(int i=0;i<h;i++)for(int j=0;j<w;j++){
    used[i][j] = false;
  }
  queue<int> qy,qx,qd;
  used[sy][sx] = true;
  qy.push(sy); qx.push(sx); qd.push(0);
  while(!qy.empty()){
    int y,x,d;
    y = qy.front(); qy.pop();
    x = qx.front(); qx.pop();
    d = qd.front(); qd.pop();
    if(y==gy && x==gx)return d;
    for(int i=0;i<4;i++){
      int ny = y+dy[i];
      int nx = x+dx[i];
      int nd = d+1;
      if(ny<0 || nx<0 || ny>=h || nx>=w)continue;
      if(used[ny][nx])continue;
      if(mp[ny][nx] == 1)continue;
      used[ny][nx] = true;
      qy.push(ny); qx.push(nx); qd.push(nd);
    }
  }
  return -1;
}

int main(){
  scanf("%d%d%d",&h,&w,&n);
  for(int i=0;i<h;i++){
    char s[1001];
    scanf("%s",&s);
    for(int j=0;j<w;j++){
      char c = s[j];
      if(c=='X'){
        mp[i][j] = 1;
      }else{
        mp[i][j] = 0;
        if(c=='S'){
          py[0] = i;
          px[0] = j;
        }else if(c!='.'){
          py[c-'0'] = i;
          px[c-'0'] = j;
        }
      }
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    ans += bfs(py[i],px[i],py[i+1],px[i+1]);
  }
  printf("%d\n",ans);
  return 0;
}