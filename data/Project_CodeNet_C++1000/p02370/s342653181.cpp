#include<bits/stdc++.h>
using namespace std;

signed main(){

  int v,e;
  cin>>v>>e;
  vector<vector<int>> adj(v);
  vector<int> deg(v);
  for(int i=0;i<e;++i){
    int s,t;cin>>s>>t;
    adj[s].emplace_back(t);
    deg[t]++;
  }

  queue<int> que;
  for(int i=0;i<v;++i)if(deg[i]==0)que.emplace(i);
  vector<int> res;
  while(!que.empty()){
    int v = que.front();
    que.pop();
    res.emplace_back(v);
    for(auto nv:adj[v]){
      deg[nv]--;
      if(deg[nv]==0)que.emplace(nv);
    }
  }

  for(auto a:res)cout<< a <<endl;

}
