#include<bits/stdc++.h>
using namespace std;
vector<int>p;
vector<int>rank;
int find(int x){
  if(x==p[x]){
    return x;
  }
  return p[x]=find(p[x]);
}
int same(int x,int y){
  if(find(x)==find(y)){
    return 1;
  }
  return 0;
}
void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(rank[x]>rank[y]){
    p[y]=x;
  }else{
    p[x]=y;
    if(rank[x]==rank[y]){
      rank[y]++;
    }
  }
}
int main(){
  int n,q;
  cin>>n>>q;
  for(int i=0;i<n;i++){
    p.push_back(i);
    rank.push_back(0);
  }
  int co,x,y;
  for(int i=0;i<q;i++){
    cin>>co>>x>>y;
    if(co==0){
      unite(x,y);
    }else{
      cout<<same(x,y)<<endl;
    }
  }
  return(0);
}

