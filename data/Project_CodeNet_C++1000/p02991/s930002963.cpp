#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

int dist[100100][3];

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int> > to(n);
  rep(i,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    to[u].push_back(v);
  }
  int s,t;
  cin >> s >> t;
  s--; t--;
  queue<i_i> q;
  q.push(i_i(s,0));
  rep(i,n)rep(j,3) dist[i][j]=inf;
  dist[s][0]=0;
  while(q.size()){
    int v=q.front().first;
    int r=q.front().second;
    q.pop();
    int nr=(r+1)%3;
    rep(i,to[v].size()){
      int nv=to[v][i];
      if(dist[nv][nr]==inf){
        dist[nv][nr]=dist[v][r]+1;
        q.push(i_i(nv,nr));
      }
    }
  }
  if(dist[t][0]==inf){
    cout << -1 << endl;
    return 0;
  }
  int ans=dist[t][0]/3;
  cout << ans << endl;
}