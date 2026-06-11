#include<bits/stdc++.h>
using namespace std;
const int MAX=10000;
const int INF=123456789;
vector<pair<int,int> > G[MAX];
list<int> out;
int indeg[MAX];
bool V[MAX];
int n;
void bfs(int s){
  queue<int> q;
  q.push(s);
  V[s]=true;
  while(!q.empty()){
    int u=q.front();q.pop();
    out.push_back(u);
    for(int i=0;i<G[u].size();i++){
      int v=G[u][i].first;
      indeg[v]--;
      if(indeg[v]==0&&!V[v]){
        V[v]=true;
        q.push(v);
      }
    }
  }
}

void toposort(){
  for(int i=0;i<n;i++){
      indeg[i]=0;
  }
  for(int u=0;u<n;u++){
    for(int i=0;i<G[u].size();i++){
      int v=G[u][i].first;
      indeg[v]++;
    }
  }

  for(int u=0;u<n;u++){
    if(indeg[u]==0&&!V[u]){
       bfs(u);
    }
  }
}

int main(){
  int e;
  cin>>n>>e;
  for(int i=0;i<n;i++){
    V[i]=false;
  }

  for(int i=0;i<e;i++){
    int s,t;
    cin>>s>>t;
    G[s].push_back(make_pair(t,1));
  }

  toposort();

  for(list<int>::iterator p=out.begin();p!=out.end();p++){
    cout<<*p<<endl;
  }
return 0;
}