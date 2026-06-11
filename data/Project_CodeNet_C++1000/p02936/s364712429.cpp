#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>G;
vector<bool>seen;
vector<int>cont;
void dfs(int v,int p=-1){
  seen[v]=true;

  for(auto nv:G[v]){
    if(seen[nv])continue;
    if(nv==p)continue;
    cont[nv]+=cont[v];
  
    dfs(nv,v);
  }
}
int main(){
  int N,Q;
  cin>>N>>Q;
  G.resize(N);
  seen.assign(N,false);
  cont.assign(N,0);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=0;i<Q;i++){
    int dot,num;
    cin>>dot>>num;
    cont[--dot]+=num;
  }
  dfs(0);
  for(int i=0;i<N;i++){
    cout<<cont[i]<<" ";
  }
}