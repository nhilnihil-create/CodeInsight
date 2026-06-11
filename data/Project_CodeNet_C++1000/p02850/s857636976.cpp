#include<bits/stdc++.h>
using namespace std;
struct Edge{
  int to;
  int id;
};
vector<vector<Edge>>G;
vector<int>color;
void dfs(int v,int p=-1,int parent_color=-1){
  int k=1;
  for(auto nextv:G[v]){
    if(nextv.to==p)continue;
    if(color[nextv.id]!=-1)continue;
    if(parent_color==k)k++;
    color[nextv.id]=k;
    //cout<<"nextv"<<nextv.to<<endl;
    //cout<<"parent_coor"<<parent_color<<endl;
    k++;
    dfs(nextv.to,v,color[nextv.id]);
  }
}
int main(){
  int N;
  cin>>N;
  G.resize(N);
  color=vector<int>(N-1,-1);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a].push_back(Edge{b,i});
    G[b].push_back(Edge{a,i});
  }
  dfs(0);
  int max_degree=0;
  for(int i=0;i<N;i++){
    max_degree=max(max_degree,(int)G[i].size());
  }
  cout<<max_degree<<endl;
  for(int i=0;i<N-1;i++){
    cout<<color[i]<<endl;
  }
}