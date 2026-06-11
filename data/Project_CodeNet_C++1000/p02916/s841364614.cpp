#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
  cin>>N;
  ll ans=0;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) {
cin>>A[i];
  }
   vector<ll> B(N);
  for(ll i=0;i<N;i++) {
cin>>B[i];
  }
   vector<ll> C(N-1);
  for(ll i=0;i<N-1;i++) {
cin>>C[i];
  }
  
 for(ll i=0;i<N;i++) {
ans+=B[i];
 }
  
  for(ll i=0;i<N-1;i++) {
    ll k=A[i];
    if(A[i+1]==k+1) {
ans+=C[k-1];
    }
  }
  
  cout<<ans<<endl;
}


  
  
  
  
  
  
  
  
  
  
  
  
  