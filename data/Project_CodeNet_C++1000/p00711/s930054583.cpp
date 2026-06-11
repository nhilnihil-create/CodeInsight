#include<cstdio>

bool done[21][21];
int W,H;
char s[21][21];
bool map[21][21];

void init(){
  for(int i=0;i<21;i++){
    for(int j=0;j<21;j++){
      done[i][j]=false;
      map[i][j]=false;
      s[i][j]=0;
    }}
}

void solve(int h,int w){
  if(s[h][w]=='.' || s[h][w]=='@'){
    map[h][w]=true;
    done[h][w]=true;
    if(h-1 >=0 && done[h-1][w]==false) solve(h-1,w);
    if(h+1 < H && done[h+1][w]==false) solve(h+1,w);
    if(w-1 >=0 && done[h][w-1]==false) solve(h,w-1);
    if(w+1 <W && done[h][w+1]==false) solve(h,w+1);
  }
  else{
    map[h][w]=false;
    done[h][w]=true;
  }

  return;

}
int main(){
  while(1){
    init();
    scanf("%d%d",&W,&H);
    if(W==0 && H==0) break;
    for(int i=0;i<H;i++)
      scanf("%s",&s[i]);
    int sw,sh;
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(s[i][j]=='@'){
          sw=j;
          sh=i;
        }}}

    solve(sh,sw);


    int ans=0;

    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(map[i][j]==true)
          ans++;
      }}

    printf("%d\n",ans);
  }
  return 0;

}