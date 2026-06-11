 #include<stdio.h>
#define Gray 0
#define White 1
#define Black 2
int time;
int d[101],f[101],color[101],Adj[101][101];  
int n;

void DFS_Visit(int u){
  int i;  
  color[u]=Gray;
  d[u]=++time;
  for(i=1;i<=n;i++){
    if(color[i]==White && Adj[u][i]==1) DFS_Visit(i);
  }
  color[u]=Black;
  f[u]=++time;
}

void DFS(){
  int i;
  for(i=1;i<=n;i++){
    color[i]=White;
  }
  time=0;
  for(i=1;i<=n;i++){
    if(color[i]==White) DFS_Visit(i);
}
}

main(){
  
  int k,i,j,t,g;

  scanf("%d",&n);
    for(i=0;i<=n;i++){
      for(j=0;j<=n;j++){
	Adj[i][j]=0;
      }
    } 
    
    for(i=1;i<=n;i++){
      scanf("%d",&g);    
      scanf("%d",&k);
      for(j=1;j<=k;j++){
	scanf("%d",&t);
	Adj[g][t]=1;   
      }
    } DFS();
    
    for(i=1;i<=n;i++){
   
      printf("%d %d %d\n",i,d[i],f[i]);
    }
    return 0;
}