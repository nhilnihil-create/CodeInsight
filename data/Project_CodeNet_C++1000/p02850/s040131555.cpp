#include<bits/stdc++.h>
using namespace std;
struct Edge{int to;int id;};
vector<vector<Edge>> g;
vector<int> ans;
void dfs(int v,int parent_color=-1,int parent=-1){
  int now_color=1;
  for(auto t:g[v]){
    int next_v=t.to;
    int next_id=t.id;
    if(next_v==parent)continue;
    if(now_color==parent_color)now_color++;
    ans[next_id]=now_color;now_color++;
    dfs(next_v,ans[next_id],v);
  }
}
int main(){
  int n;
  cin>>n;
  g.resize(n);
  ans.resize(n-1);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    g[a].push_back(Edge{b,i});
    g[b].push_back(Edge{a,i});
  }
  dfs(0);
  int max_degree=0;
  for(int i=0;i<n;i++){
    max_degree=max(max_degree,int(g[i].size()));
  }
  cout<<max_degree<<endl;
  for(int i=0;i<n-1;i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}