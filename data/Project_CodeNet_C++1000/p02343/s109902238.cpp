#include<iostream>
#include<vector>
using namespace std;

int par[10000];
int rank[10000];

int find(int x){
  
  if(x == par[x]){
    return x;
  }else{
    par[x]=find(par[x]);
  }
  return par[x];
  
}
bool same(int x,int y){
  int x_oya,y_oya;
  
  x_oya=find(x);
  y_oya=find(y);

  if(x_oya == y_oya){
    return true;
  }else{
    return false;
  }
  
}
void unite(int x,int y){
  
  int x_oya,y_oya;

  x_oya=find(x);
  y_oya=find(y);
  
  if(rank[x_oya] > rank[y_oya]){
    par[y_oya]=x_oya;
  }else if(rank[x_oya] < rank[y_oya]){
    par[x_oya]=y_oya;
  }else{
    par[y_oya]=x_oya;
    rank[x_oya]++;
  }
  
}
 
int main(){
  
  int n,q,com,x,y;
  
  cin >>n>>q;

  for(int i=0 ; i < n ; i++){
    par[i]=i;
    rank[i]=0;
  }
  

  for(int i=0 ; i < q ; i++){
  
    cin >>com;

    if(com == 0){
      cin >>x>>y;
      unite(x,y);
    }else{
      cin >>x>>y;
      cout <<same(x,y)<<endl;
    }
  
  }


  return 0;
}