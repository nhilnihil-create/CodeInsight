#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define MAX 100005
#define int long long
using namespace std;

const int MOD=1000000007;
const int INF=1000000009;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct Edge{
  int src,dst,wei;
  Edge(int s=0,int d=0,int w=0):src(s),dst(d),wei(w){}
};
using Graph = vector<vector<Edge>>;

vector<int> Toposort(Graph&g){
  int v=g.size(),k=0;
  vector<int> res(v),in(v);
  for(int i=0;i<v;i++){
    for(int j=0;j<g[i].size();j++){
      Edge x=g[i][j];
      in[x.dst]++;
    }
  }
  queue<int> q;
  for(int i=0;i<v;i++){
    if((in[i]==0))q.push(i);
  }
  while(!q.empty()){
    int u=q.front();
    q.pop();
    res[k++]=u;
    for(int i=0;i<g[u].size();i++){
      Edge &e=g[u][i];
      in[e.dst]--;
      if(in[e.dst]==0)q.push(e.dst);
    }
  }
  return res;
}



signed main(){
  int v,e;
  cin>>v>>e;
  Graph g(v);
  rep(i,e){
    int s,t;
    cin>>s>>t;
    g[s].pb(Edge(s,t,0));
  }
  vector<int> ans=Toposort(g);
  rep(i,v){
    cout<<ans[i]<<endl;
  }

  return 0;
}