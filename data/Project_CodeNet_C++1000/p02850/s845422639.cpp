#include<bits/stdc++.h>
using namespace std;
int MAX=0;
struct edge{int to;int id;};
vector<vector<edge>>G;
vector<bool>seen;
vector<int>color;
void dfs(int v,int p=-1,int cr=-1){
  seen[v]=true;
  int k=1;
  for(auto nx:G[v]){
    if(nx.to==p)continue;
    if(seen[nx.to])continue;
    if(cr==k)k++;
    color[nx.id]=k;
    MAX=max(MAX,k);
    k++;
    dfs(nx.to,v,color[nx.id]);
  }
}
int main(){
  int N;
  cin>>N;
  G.resize(N);
  seen.assign(N,false);
  color.resize(N-1,0);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a].push_back(edge{b,i});
    G[b].push_back(edge{a,i});
  }
  dfs(0);
  cout<<MAX<<endl;
  for(int i=0;i<N-1;i++){
    cout<<color[i]<<endl;
  }
}