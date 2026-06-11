#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> G(n);
  rep(i,m){
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll ans=0;
  queue<ll> que;
  vector<ll> dis(n,-1);
  for(ll i=0;i<n;i++){
    que.push(i);
    ll sum=0;
    while(!que.empty()){
      ll v=que.front();
      que.pop();
      for(ll nv: G[v]){
        if(dis.at(nv)!=-1){
          continue;
        }
        dis.at(nv)=dis.at(v)+1;
        que.push(nv);
        sum++;
      }
    }
    ans=max(ans,sum);
  }
  if(ans==0){
    ans=1;
  }
 
  cout << ans;
}