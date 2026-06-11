#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int INF=(1<<21);
int n,M[101][101];
int d[101]; //最短距離を記録(到達不可な時はINF)
void bfs(int s){
  queue<int>q;
  q.push(s);//始点sをいれる(訪問)
  for(int i=0;i<n;i++) d[i]=INF;
  d[s]=0;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int v=0;v<n;v++){
      if(M[u][v]==0) continue; //辺がない
      if(d[v]!=INF) continue; //訪問したことがある
      d[v]=d[u]+1; //vは未訪問の頂点であり、隣接しているためd[u]に1を足す
      q.push(v); //vを始点に
    }
  }
  for(int i=0;i<n;i++){
    cout<<i+1<<" "<<( (d[i]==INF)?(-1):d[i] )<<endl;
  } //到達不可能か
}
int main(){
  int u,k,v;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(int j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  bfs(0);
  return 0;
}

