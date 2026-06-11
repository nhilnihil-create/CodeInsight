#include<cstdio>

int h,w;
int ans;
char map[102][102];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x,int y,char c){
  map[x][y] = 'A';
  for(int i=0;i<4;i++){
    if(map[x+dx[i]][y+dy[i]]==c){
      dfs(x+dx[i],y+dy[i],c);
    }
  }
}

int solve(){
  for(int i=0;i<=h+1;i++){
    for(int j=0;j<=w+1;j++){
      if(i==0||j==0||i==h+1||j==w+1) map[i][j] = 'A';
      else scanf(" %c ",&map[i][j]);
    }
  }
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(map[i][j]!='A'){
        ans++;
        dfs(i,j,map[i][j]);
      }
    }
  }
  printf("%d\n",ans);
}
int main(){
  while(1){
    ans = 0;
    scanf("%d %d",&h,&w);
    if(h==0&&w==0) return 0;
    solve();
  }
}