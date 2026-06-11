#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
vector<ll> A(N+1);
  ll sum=0;
  for(ll i=0;i<N+1;i++) {
cin>>A[i];
    sum+=A[i];
  }
  
  vector<ll> B(N);
  for(ll i=0;i<N;i++) {
    cin>>B[i];
  }
  
  for(ll i=0;i<N;i++) {
if(A[i]>=B[i]) {
A[i]-=B[i];
continue;
}
    else {
    B[i]-=A[i];
      A[i]=0;
      
      if(B[i]>A[i+1]) {
A[i+1]=0;
        continue;
      }
      else {
A[i+1]-=B[i];
        continue;
      }
    }
  }
  
  ll ans=0;
  for(ll i=0;i<N+1;i++) {
    ans+=A[i];
  }
  
  cout<<sum-ans<<endl;
}


  
  
  
  
