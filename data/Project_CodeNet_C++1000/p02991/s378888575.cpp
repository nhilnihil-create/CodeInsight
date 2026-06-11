#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
int main(){
  int N,M;
  cin>>N>>M;
  Graph G(N);
  for(int i=0;i<M;i++){
  int u,v; cin>>u>>v; u--;v--;
    G[u].push_back(v);
  }int s,t;cin>>s>>t; s--; t--;
  vector<vector<int>>dist(3,vector<int>(N,-1));
  dist[0][s]=0;
  vector<int>dist1(N,-1); dist1[s]=0;
  queue<pair<int,int>>que;pair<int,int>p(s,0);que.push(p);
  while(!que.empty()){
  pair<int,int>q=que.front();
    que.pop();int v=q.first;
    for(auto u:G[v]){
      int x=q.second+1;
    int i=x%3;
      if(dist[i][u]!=-1)
        continue;
      else{
      dist[i][u]=x;
        dist1[u]=x;
        pair<int,int>r(u,x);
        que.push(r);
      }
    }
  
  }if(dist[0][t]==-1)
    cout<<-1<<endl;
  else
    cout<<dist[0][t]/3<<endl;
  
  return 0;
}