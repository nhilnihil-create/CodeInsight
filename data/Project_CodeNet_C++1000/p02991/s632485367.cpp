#include <bits/stdc++.h>
using namespace std;

queue<int> que;
void dfs(vector<vector<int>> &graph,vector<int> &dis,vector<vector<bool>> &visited,int V,int cnt,int st){
  if(cnt==3){
    dis.at(V)=dis.at(st)+1;
    que.push(V);
    return;
  }

  for(int i=0;i<graph.at(V).size();i++){
    int nv=graph.at(V).at(i);
    if(visited.at(nv).at((cnt+1)%3))  continue;
    visited.at(nv).at((cnt+1)%3)=true;
    dfs(graph,dis,visited,nv,cnt+1,st);
  }
}

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> graph(N);
  for(int i=0;i<M;i++){
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    graph.at(u).push_back(v);
  }
  int S,T;
  cin >> S >> T;
  S--;
  T--;

  vector<int> dis(N,1e9);
  vector<vector<bool>> visited(N,vector<bool>(3,false));
  dis.at(S)=0;
  visited.at(S).at(0)=true;
  que.push(S);
  while(!que.empty()){
    int v=que.front();
    que.pop();
    dfs(graph,dis,visited,v,0,v);
  }
  if(dis.at(T)==1e9)  cout << -1 << endl;
  else  cout << dis.at(T) << endl;

  return 0;
}