#include<iostream>
#define n_max 100000
using namespace std;
int find(int);
int com[n_max],x[n_max],y[n_max],par[n_max],rank[n_max];

bool same(int x,int y){
  return find(x) == find(y);
}

void unite(int x,int y){
  
  x= find(x);
  y= find(y);
  

  if(rank[x] > rank[y]){
    par[y] = x;
  }
  else {
    par[x] = y;
    if(rank[x] == rank[y]) rank[y]++;
  }

}


int find(int x){
  if(x != par[x]){
    par[x] = find(par[x]);
  }
  return par[x];
}

int main(){
  
  int n,q;
  cin >>n>>q;
  
  for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=0;
  }
  
  for(int i=0;i<q;i++){
    cin >>com[i]>>x[i]>>y[i];

    if(com[i]){
      same(x[i],y[i]);
      cout <<same(x[i],y[i])<<endl;
    }
    else{
      unite(x[i],y[i]);
    }
    
    
  }


 
  
}