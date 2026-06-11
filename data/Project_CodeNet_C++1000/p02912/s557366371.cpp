#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,M;
  cin>>N>>M;
 priority_queue<ll> S;
  for(ll i=0;i<N;i++) {
ll A;
    cin>>A;
    S.push(A);
  }
  
 for(ll i=0;i<M;i++) {
ll K=S.top()/2;
   S.pop();
   S.push(K);
 }
  ll ans=0;
  while(!S.empty()) {
ans+=S.top();
    S.pop();
  }
  
  cout<<ans<<endl;
}
   

  
  
  
  
  
  