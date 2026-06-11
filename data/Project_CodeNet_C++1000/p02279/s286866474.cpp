#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)
#define llong long long
#define IFY 2000000000
#define MAX 100005
#define NIL -1
using namespace std;
struct Node {int p,l,r;};
Node T[MAX];
int D[MAX];
void print(int u){
  int j,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",D[u]);
  if(T[u].p==NIL)printf("root, ");
  else if(T[u].l==NIL)printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  for(j=0,c=T[u].l;c!=NIL;j++,c=T[c].r){
    if(j) printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}
int rec(int u,int p){
  D[u]=p;
  if(T[u].l!=NIL) rec(T[u].l,p+1);
  if(T[u].r!=NIL) rec(T[u].r,p);
}
int main(){
  int n,v,d,c,l,r,j;
  scanf("%d",&n);
  REP(i,n) T[i].p=T[i].l=T[i].r=NIL;
  REP(i,n){
    scanf("%d %d",&v,&d);
    REP(j,d){
      scanf("%d",&c);
      if(j==0) T[v].l=c;
      else T[l].r=c;
      l=c;
      T[c].p=v;
    }
  }
  REP(i,n) if(T[i].p==NIL) r=i;
  rec(r,0);
  REP(i,n) print(i);
  return 0;
}