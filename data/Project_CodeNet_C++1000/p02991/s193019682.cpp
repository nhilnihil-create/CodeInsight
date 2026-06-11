#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
const int INF=1001001001;


int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> to(n);
  rep(i,m){
    int u,v;

    cin>>u>>v;
    u--;v--;
    to[u].push_back(v);
  }
  int s,t;
  cin>>s>>t;
  s--;t--;
  int dist[n][3];
  rep(i,n)rep(j,3)dist[i][j]=INF;
  dist[s][0]=0;
  queue<P> q;
  q.push(P(s,0));
  while (!q.empty()){
    int t1,t2;
    t1=q.front().first;
    t2=q.front().second;
    q.pop();
    for(int t3:to[t1]){
      int nl=(t2+1)%3;
      if (dist[t3][nl]!=INF)continue;
      dist[t3][nl]=dist[t1][t2]+1;
      q.push(P(t3,nl));
    }
  }
  int ans=dist[t][0];
  if (ans==INF)ans=-1;
  else(ans=ans/3);
  cout<<ans;
}
