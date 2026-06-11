#include <stdio.h>
#include <stdlib.h>
typedef struct data{
  int u,v,w;
}data;
int adj[10001];
int cmp(void const *a,void const *b){
  return ((data*)a)->w > ((data*)b)->w;
}
int sc(int x){
  if(adj[x]==-1)return x;
  else{
    adj[x]=sc(adj[x]);
    return adj[x];
  }
}
int Union(int x,int y){
  adj[x]=y;
}
int main(){
  int i,n,u,v,w,sum,m,C,k;
  data E[100001];
  scanf("%d%d",&n,&m);

  for(i=0;i<=n;i++){
    adj[i]=-1;
  }
  i=0;
  for(i=0;i<m;i++){
    scanf("%d%d%d",&u,&v,&w);
    E[i].u=u;
    E[i].v=v;
    E[i].w=w;
  }
  qsort(E,m,sizeof(data),cmp);

  int selected = 0;
  i=0;
  sum=0;
  while(selected<n-1){
    if(sc(E[i].u)!=sc(E[i].v)){
      selected++;
      sum+=E[i].w;
      Union(sc(E[i].u),sc(E[i].v));
    }
    i++;
  }
  printf("%d\n",sum);
  return 0;
}

