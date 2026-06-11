#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,M,K;
  cin>>N>>M>>K;
  vector<ll> A(N);
  vector<ll> B(M);
  for(ll i=0;i<N;i++) {
    cin>>A[i];
  }
  for (ll i=0;i<M;i++) {
cin>>B[i];
  }
ll Aindex=-1;
  ll Bindex=-1;
  ll min=0;
  for(ll i=0;i<N;i++) {
if(min+A[i]<=K) {
min+=A[i];
  Aindex=i;
}
 else {
   break;
 }
  }
  
  for(ll i=0;i<M;i++) {
if(min+B[i]<=K) {
  min+=B[i];
  Bindex=i;
}
    else {
break;
    }
  }
  
  ll ans=Aindex+Bindex+2;
  
  while(Aindex>=0) {
min-=A[Aindex];
    Aindex--;
    ll index=Bindex;
    
    for(ll i=index+1;i<M;i++) {
      if(min+B[i]<=K) {
min+=B[i];
        Bindex=i;
      }
      else {
break;
      }
    }
    if(ans<Aindex+Bindex+2) {
      ans=Aindex+Bindex+2;
    }

  }
  
  cout<<ans<<endl;
}
    
     

  
  
  
  
  
  
  
