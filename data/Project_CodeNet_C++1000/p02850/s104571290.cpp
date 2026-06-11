#include<bits/stdc++.h>
using namespace std;

struct Edge{
  int to;
  int id;
};
vector<vector<Edge>>G;
vector<bool>seen;
vector<int>ans;

void dfs(int v,int p=-1,int p_color=-1){
  seen[v]=true;
  int tmp=1;
  for(auto a:G[v]){
    int next_v=a.to;
    int ID=a.id;//辺のID
    if(next_v==p)continue;
    if(seen[next_v])continue;
    if(tmp==p_color)tmp++;
    ans[ID]=tmp;
    tmp++;
    dfs(next_v,v,ans[ID]);
  }
}
int main(){
  int n;
  cin>>n;
  G.resize(n);
  seen.assign(n,false);
  ans.resize(n-1);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a].push_back(Edge{b,i});
    G[b].push_back(Edge{a,i});
  }

  dfs(0);
  int max_deg=0;
  for(int i=0;i<n-1;i++){
    max_deg=max(max_deg,ans[i]);
  }
  cout<<max_deg<<endl;
  for(int i=0;i<n-1;i++){
    cout<<ans[i]<<endl;
  }

}