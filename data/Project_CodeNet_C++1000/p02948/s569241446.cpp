#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,M;
  cin>>N>>M;
 vector<pair<ll,ll>> vec(N);
  for(ll i=0;i<N;i++) {
ll A,B;
    cin>>A>>B;
    vec[i]=make_pair(B,A);
  }
  
  sort(all(vec));
  reverse(all(vec));
  
  vector<vector<ll>> note(M,vector<ll>(0));
  for(ll i=0;i<N;i++) {
if(vec[i].second>M) {
continue;
}
    note[vec[i].second-1].push_back(vec[i].first);
  }
  
 
  ll ans=0;
  priority_queue<tuple<ll,ll,ll>> S;
  for(ll i=1;i<=M;i++) {
if(note[i-1].size()>0) {
S.push(make_tuple(note[i-1][0],i-1,0));
}
    if(S.empty()) {
continue;
    }
    ll A,B,C;
  tie(A,B,C)=S.top();
    S.pop();
    ans+=A;
    if(note[B].size()>C+1) {
S.push(make_tuple(note[B][C+1],B,C+1));
    }
  }
  
  
  cout<<ans<<endl;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  