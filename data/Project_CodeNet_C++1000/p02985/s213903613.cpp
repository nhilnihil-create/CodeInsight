#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

ll K;

ll f(vector<int> g,bool x){
  ll ans = 1LL;
  if(x){
    for(ll i = 0LL; i < (ll)g.size();i++){
      ans=(ans*(K-i-1LL))%mod;
    }
  }
  if(!x){
    for(ll i = 0; i < (ll)g.size();i++){
      ans=(ans*(K-i-2LL))%mod;
    }
  }
  return ans;
}

int main() {
  ll N;
  cin>>N>>K;
  vector<vector<int>> g(N);
  for(int i = 0; i < N-1; i++) {
    int x,y;
    cin>>x>>y;
    g[x-1].push_back(y-1);
    g[y-1].push_back(x-1);
  }
  queue<int> q;
  vector<bool> seen(N,false);
  q.push(0);
  seen[0]=true;
  vector<int>parent(N,-1),dep(N,0);
  vector<vector<int>> child(N);
  int d = 0;
  while(!q.empty()){
    d++;
    int t= q.front();
    q.pop();
    for(auto nx:g[t]){
      if(seen[nx]) continue;
      seen[nx]=true;
      q.push(nx);
      child[t].push_back(nx);
      parent[nx]=t;
      dep[nx]=d;
    }
  }
  queue<int> bfs;
  ll ans = K;
  bfs.push(0);
  while(!bfs.empty()){
    int t = bfs.front();
    bfs.pop();
    ans=(ans*f(child[t],(dep[t]<1)))%mod;
    for(auto x:child[t]){
      bfs.push(x);
    }
  }
  cout<<ans<<endl;
}
