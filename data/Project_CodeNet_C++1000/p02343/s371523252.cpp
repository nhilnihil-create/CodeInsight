#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N,Q;
int par[10000];
int rank[10000];
int find(int x){
  if(par[x]==x)return x;
  else return par[x]=find(par[x]);
}
bool same(int x,int y){
  return find(x)==find(y);
}
void unite(int x,int y){
   x=find(x);
   y=find(y);
  if(x==y)return ;
  if(rank[x]<rank[y])par[x]=y;
  else {
    par[y]=x;
    if(rank[x]==rank[y])rank[x]++;
  }
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    rank[i]=0;
    par[i]=i;
  }
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int com,x,y;
    scanf("%d %d %d",&com,&x,&y);
    if(com==0)unite(x,y);
    else {
      if(same(x,y))puts("1");
      else puts("0");
    }
  }
  return 0;
}