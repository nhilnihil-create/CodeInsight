#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<pair<int,ll>>>;
using pp=pair<ll,pair<ll,ll>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000000000000000

vector<int> parent;
int find(int x){
  int y=parent[x];
  while(y!=parent[y]){
    y=find(y);
  }
  return parent[x]=y;
}

void unite(int a,int b){
  int x=find(a);
  int y=find(b);
  if(x!=y){
    parent[x]=y;
  }
}

int main(){
  int N,Q;
  cin>>N>>Q;

  parent.resize(N);
  for(int i=0;i<N;i++){
    parent[i]=i;
  }

  for(int i=0;i<Q;i++){
    int t,u,v;
    cin>>t>>u>>v;
    if(t==0){
      unite(u,v);
    }else{
      if(find(u)==find(v)){
        cout<<1<<endl;
      }else{
        cout<<0<<endl;
      }
    }
  }
}
