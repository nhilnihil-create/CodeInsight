#include<cstdio>
struct N{int p,l,r;};
N T[100000];
int n,d,k,c,x,r,i,j,m,o,D[100000];
void R(int r,int d){
  D[r]=d;
  if(T[r].r+1)R(T[r].r,d);
  if(T[r].l+1)R(T[r].l,d+1);
}
main(){
  scanf("%d",&n);
  for(;j<n;++j)T[j].p=T[j].l=T[j].r=-1;
  for(;i++<n;)
    for(scanf("%d%d",&d,&k),j=0;j<k;x=c){
      scanf("%d",&c);
      T[c].p=d;
      j++?T[x].r=c:T[d].l=c;
    }
  for(;m<n;++m)r=T[m].p+1?r:m;
  R(r,0);
  for(;o<n;++o){
    printf("node %d: parent = %d, depth = %d, ",o,T[o].p,D[o]);
    printf(T[o].p+1?T[o].l+1?"internal node, [":"leaf, [":"root, [");
    for(i=0,j=T[o].l;j+1;)printf(i++?", %d":"%d",j),j=T[j].r;
    printf("]\n");
  }
}