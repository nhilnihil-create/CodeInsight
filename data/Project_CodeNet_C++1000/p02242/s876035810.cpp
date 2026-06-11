#include <stdio.h>
#define INF 100000000 
#define N 100
 
int n;
int size[N];
int to[N][N];
int cost[N][N];
int dist[N];
  
void DFS(int,int);
  
main(int argc,char *argv[]){
  int i, j;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    int u;
    scanf("%d", &u);
    scanf("%d", &size[u]);
    for(j=0;j<size[u];j++){
      scanf("%d", &to[u][j]);
      scanf("%d", &cost[u][j]);
    }
  }
  for(i=0;i<n;i++) dist[i] = INF;
  DFS(0, 0);
  for(i=0;i<n;i++){
    printf("%d %d\n", i, dist[i]);
  }
  return 0;
}
void DFS(int p, int c){
  int i;
  dist[p] = c;
  for(i=0;i<size[p];i++){
    if(dist[to[p][i]] > c + cost[p][i])
      DFS(to[p][i], c + cost[p][i]);
  }
}