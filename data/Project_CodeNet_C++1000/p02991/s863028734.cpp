#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

vector<vector<int>> G(101010);
ll dist[101010][3];
int N,M,S,T;

int main(){
  cin>>N>>M;
  rep(i,M){
    int u,v; cin>>u>>v; u--,v--;
    G[u].push_back(v);
  }
  cin>>S>>T; S--,T--;
  
  rep(i,N) rep(j,3) dist[i][j]=-1;
  queue<pair<int,int>> que;
  que.push({S,0});
  dist[S][0]=0;
  while(que.size()){
    auto p=que.front(); que.pop();
    int v=p.first,cur=p.second,nex=(cur+1)%3;
    if(v==T&&cur==0){
      cout<<dist[T][0]/3<<endl;
      return 0;
    }
    for(int u:G[v]){
      if(dist[u][nex]==-1){
        dist[u][nex]=dist[v][cur]+1;
        que.push({u,nex});
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}