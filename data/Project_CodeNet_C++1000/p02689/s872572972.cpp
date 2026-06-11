#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int n,m; cin>>n>>m;
  vector<int> h(n);
  for(int i=0;i<n;i++)cin>>h[i];
  
  Graph G(n);
  for (int i=0;i<m;++i) {
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue<int> que;
  int count=0;
  que.push(0);
  while(!que.empty()){
    int v=que.front();que.pop();
    bool ok=true;
    for(auto nv:G[v]){
      if(h[v]<=h[nv]){
        ok=false;
        break;
      }
    }
    if(ok)count++;
    if(v<n-1)que.push(v+1);
  }
  cout << count << endl;
}