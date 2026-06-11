#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rrep(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define int long long
typedef long long ll;

using namespace std;
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin>>n;
  vector<vector<int>> G(n);
  vector<pair<int,int>> edge;
  rep2(i,1,n){
    int a,b; cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    edge.emplace_back(a,b);
  }

  int K=0;
  map<pair<int,int>,int> I; //(edge, color)
  vector<int> cs(n,0); // color of edge between its parent

  vector<int> used(n,0);
  queue<int> que;
  used[0]=1; //color of the root
  que.emplace(0);
  while(!que.empty()){
    int v=que.front(); que.pop();
    if(K < (int)G[v].size()) K=G[v].size();
    int cur=1;
    for(int u:G[v]){
      if(used[u]) continue;
      if(cur==cs[v]) cur++;
      cs[u]=I[make_pair(u,v)]=I[make_pair(v,u)]=cur++;
      used[u]=1;
      que.emplace(u);
    }
  }

  cout << K << endl;
  for(auto p:edge) cout << I[p] << endl;
  return 0;
}
