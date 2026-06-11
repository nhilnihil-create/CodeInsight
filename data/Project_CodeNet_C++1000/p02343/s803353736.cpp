#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>p; //ノードxの親
vector<int>rank; //ノードxの高さ
int find(int x){ //代表を求める関数
  if(x==p[x]) return x;
  return p[x]=find(p[x]);
}
int same(int x,int y){ //x,yの一致
  if(find(x)==find(y)) return 1;
  else return 0;
}
void unite(int x,int y){ //xとyを合併
  x=find(x);
  y=find(y);
  if(rank[x]>rank[y]){
    p[y]=x;
  }else{
    p[x]=y;
    if(rank[x]==rank[y]){
      rank[y]++; //rank[y]=rank[x]+1
    }
  }
}
int main(){
  int n,q;
  scanf("%d %d",&n,&q);
  rank.resize(n,0);
  p.resize(n,0);
  for(int i=0;i<n;i++){
    p[i]=i;
    rank[i]=0;
  }
  int com,x,y;
  for(int i=0;i<q;i++){
    scanf("%d %d %d",&com,&x,&y);
    if(com==0){
      unite(x,y);
    }else if(com==1){
      cout<<same(x,y)<<endl;
    }
  }
  return 0;
}
  
