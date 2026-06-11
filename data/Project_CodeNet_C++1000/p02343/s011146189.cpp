#include<stdio.h>
struct UF{
  int u[10001];
  void init(int x){
    for(int i=0;i<x;i++){
      u[i] = i;
    }
  }
  int unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x > y) u[x] = y;
    if(y > x) u[y] = x;
  }
  int find(int x){
    if(x != u[x]) u[x] = find(u[x]);
    return u[x];
  }
};
int main(){
  UF uf;
  int n,q,a,b,c;
  scanf("%d %d",&n,&q);
  uf.init(n);
  for(int i=0;i<q;i++){
    scanf("%d %d %d",&a,&b,&c);
    if(a) printf("%d\n",uf.find(b)==uf.find(c));
    if(!a) uf.unite(b,c);
  }
  return (0);
}