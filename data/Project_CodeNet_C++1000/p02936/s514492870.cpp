#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n,q;
  cin>>n>>q;
  int ans[220000];
   int c[220000];
  rep(i,0,220000){
   ans[i]=-1; 
    c[i]=0;
  }
 
  vector<vin> G(n,vector<int> ());
  rep(i,0,n-1){
   int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
   // cout<<a<<b<<endl;
  }
  rep(i,0,q){
    int p,x;
    cin>>p>>x;
    p--;
    
    c[p]+=x;
   // cout<<c[p]<<endl;
  }
  
  queue<int> bfs;
  bfs.push(0);
  ans[0]=c[0];
  while(!bfs.empty()){
    int v=bfs.front();
    bfs.pop();
    
    for(auto nv:G[v]){
      if(ans[nv]!=-1) continue;
      ans[nv]=ans[v]+c[nv];
      //cout<<v<<" "<<nv<<endl;
      bfs.push(nv);
    }
  }
  
  rep(i,0,n) cout<<ans[i]<<endl;
}






//木に情報を持たせておく