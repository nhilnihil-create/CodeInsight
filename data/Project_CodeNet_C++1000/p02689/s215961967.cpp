#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,M;
  cin>>N>>M;
  vector<vector<ll>>G(N);
  vector<ll>H(N);
  for(ll i=0;i<N;i++)cin>>H[i];
  vector<pair<ll,ll>>pr(M);
  for(ll i=0;i<M;i++){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    pr[i]=make_pair(a,b);

  }
  sort(pr.begin(),pr.end());
  pr.erase(unique(pr.begin(),pr.end()),pr.end());
  
  for(ll i=0;i<pr.size();i++){
    ll a=pr[i].first;
    ll b=pr[i].second;
   // cout<<a<<" "<<b<<endl;
    G[a].push_back(H[b]);
    G[b].push_back(H[a]);
  }
  // for(ll i=0;i<N;i++){
  //   cout<<i<<" ";
  //   for(ll j=0;j<G[i].size();j++){
  //     cout<<G[i][j];
  //   }
  //   cout<<endl;
  // }

  ll ans=0;
  for(ll i=0;i<N;i++){
    ll flag=1;
    for(ll j=0;j<G[i].size();j++){
      if(H[i]<=G[i][j])flag=-1;
    }
    if(flag==1){
      ans++;
 //     cout<<i<<endl;
    }
  }
  cout<<ans<<endl;
}