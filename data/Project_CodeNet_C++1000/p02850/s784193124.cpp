#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<pair<ll,ll>> vec(N-1);
  vector<vector<ll>> tree(N,vector<ll>(0));
  
  for(ll i=0;i<N-1;i++) {
ll a,b;
    cin>>a>>b;
    tree[a-1].push_back(b);
    tree[b-1].push_back(a);
    vec[i]=make_pair(a,b);
  }
  queue<pair<ll,ll>> S;
  S.push(make_pair(1,0));
         map<pair<ll,ll>,ll> W;
  
  ll ans=0;
         while(!S.empty()) {
ll a,b;
           a=S.front().first;
           b=S.front().second;
           S.pop();
           ll i=1;
           for(ll x:tree[a-1]) {
if(W.count(make_pair(x,a))) {
continue;
}
             if(i==b) {
i++;
             }
             W[make_pair(a,x)]=i;
             S.push(make_pair(x,i));
             i++;
           }
           ans=max(ans,i-1);
         }
         
       cout<<ans<<endl;
         for(ll i=0;i<N-1;i++) {
cout<<W[vec[i]]<<endl;
         }
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  