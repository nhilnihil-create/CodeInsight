#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  int N,M;
  vector<int> G[100000];
  int s,t;
  vector<vector<ll>> dp(100000,vector<ll>(3,INFll));
  cin>>N>>M;
  for(int i(0);i<M;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G[u].push_back(v);
  }
  cin>>s>>t;
  s--;t--;
  dp[s][0] = 0;
  queue<pair<int,int>> q;
  q.push({s,0});
  while(!q.empty()){
    pair<int,int> now = q.front();q.pop();
    for(auto next:G[now.first]){
      if(dp[next][(now.second+1)%3] == INFll){
        dp[next][(now.second+1)%3] = now.second + 1;
        q.push({next,now.second+1});
      }
    }
  }
  if(dp[t][0] != INFll){
    cout << dp[t][0]/3 << endl;
  }else{
    cout << -1 << endl;
  }
  return 0;
}
