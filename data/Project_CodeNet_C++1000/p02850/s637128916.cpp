#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rrep(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  vector<vector<int>> G(n);
  vector<pair<int,int>> edge;
  rep(i,n-1){
    int a,b; cin >> a >> b;
    a--;b--;
    G[a].push_back(b); G[b].push_back(a);
    edge.push_back(make_pair(a,b));
  }
  int k = 0;
  queue<int> q;
  q.push(0);
  vector<int> with_parent(n), used(n,0);
  used[0] = 1;
  map<pair<int,int>,int> f; // edge to color
  while(!q.empty()){
    int now = q.front(); q.pop();
    k = max(k,int(G[now].size()));
    int candidate = 1;
    for(auto i:G[now]){
      if(used[i]) continue;
      q.push(i); 
      if(candidate == with_parent[now]) candidate++;
      with_parent[i] = candidate;
      f[make_pair(now,i)] = candidate; f[make_pair(i,now)] = candidate;
      candidate++;
      used[i] = 1;
    }
  }
  
  cout << k << endl;
  for(auto p:edge) cout << f[p] << endl;
  
  return 0;
}