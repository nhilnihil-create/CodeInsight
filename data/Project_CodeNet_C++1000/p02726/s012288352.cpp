#include <bits/stdc++.h>
using namespace std;

queue<int> q;
bool visited[2005];
int dist[2005];

vector<int> ans(10000,0);
vector<int> adj[10000];

void bfs(int x){
  visited[x] = true;
  dist[x]=0;
  q.push(x);
  while (!q.empty()) {
  int s = q.front(); q.pop();
  // process node s
  for (auto u : adj[s]) {
  if (visited[u]) continue;
  visited[u] = true;
  dist[u] = dist[s]+1;
  q.push(u);
  }
  }
}




void solve(){
  int main,x,y;

  cin>>main>>x>>y;

  for(int i=0;i<main-1;i++){
    adj[i].push_back(i+1);
    adj[i+1].push_back(i);
  }
  adj[x-1].push_back(y-1);
  adj[y-1].push_back(x-1);

  for(int i=0;i<main;i++){
    bfs(i);
    for(int j=i;j<main-1;j++){
    ans[dist[j+1]-1]++;
    //cout<<0<<' '<<dist[j+1]<<'\n';    
    }
    for(int ii=0;ii<2005;ii++){ visited[ii]=0,dist[ii]=0;}
  }
  for(int i=0;i<main-1;i++) cout<<ans[i]<<'\n';

}
  
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t=1;
  //cin>>t;
  while(t--) solve();
}
