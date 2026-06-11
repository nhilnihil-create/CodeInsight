#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX=10000;

typedef long long ll;

int V, E;
vector<int> adj[MAX];
vector<int> ans;
int indeg[MAX], color[MAX];

void bfs(int s){
  queue<int> Q;
  Q.push(s);
  color[s]=1;
  while(Q.empty()==false){
    int u=Q.front(); Q.pop();
    ans.push_back(u);
    for(int i=0;i<adj[u].size();i++){
      int v=adj[u][i];
      indeg[v]--;
      if(indeg[v]==0 && color[v]==0){
        color[v]=1;
        Q.push(v);
      }
    }
  }
}

int main(){
  cin >> V >> E;
  //initialize
  for(int i=0;i<V;i++){
    indeg[i]=0;
    color[i]=0;
  }
  for(int i=0;i<E;i++){
    int s, t; cin >> s >> t;
    adj[s].push_back(t);
    indeg[t]++;
  }
  //topological sort
  for(int u=0;u<V;u++){
    if(indeg[u]==0 && color[u]==0) bfs(u);
  }
  for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
}