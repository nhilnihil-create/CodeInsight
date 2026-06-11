#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  vector<vector<int>> G(N);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a].push_back(b);
  }
  int S,T;
  cin>>S>>T;
  S--,T--;
  vector<int> seen(N,-1);
  vector<int> ichi(N,-1);
  vector<int> ni(N,-1);
  queue<int> q;
  q.push(S);
  seen[S]=0;
  while(!q.empty()){
    int a=q.front();
    q.pop();
    queue<int> I;
    queue<int> NI;
    for(int x:G[a]){
      if(ichi[x]==-1){
        ichi[x]=0;
        I.push(x);
      }
    }
    while(!I.empty()){
      int b=I.front();
      I.pop();
      for(int x:G[b]){
        if(ni[x]==-1){
          ni[x]=0;
          NI.push(x);
        }
      }
    }
    while(!NI.empty()){
      int b=NI.front();
      NI.pop();
      for(int x:G[b]){
        if(seen[x]==-1){
          seen[x]=seen[a]+1;
          q.push(x);
        }
      }
    }
  }
  cout<<seen[T]<<endl;
}


