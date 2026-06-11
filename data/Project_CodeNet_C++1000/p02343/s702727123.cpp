#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;
const int INF=INT_MAX/3;
const int V_MAX=10000,E_MAX=10000;
const int N=10000;

int V,E;

int par[N];
int rank[N];

int n,q;

void init(){
  for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=0;
  }
}

int find(int x){
  if(x==par[x]) return x;
  return (par[x]=find(par[x]));

}

int same(int x,int y){
  if(find(x)==find(y)) return 1;
  else return 0;
}

void unite(int x,int y){

  int rx=find(x),ry=find(y);
  if(rank[rx]<rank[ry]) par[rx]=ry;
  else{
    par[ry]=rx;
    if(rank[rx]==rank[ry]) rank[ry]++;
  }
}

void print(){
  for(int i=0;i<n;i++)
    cout<<"par["<<i<<"]"<<par[i]<<endl;
}
  
int main(){

  cin>>n>>q;
  init();
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c==0) unite(x,y);
    if(c==1) cout<<same(x,y)<<endl;
    if(c==2) print();
  }


  return 0;
}