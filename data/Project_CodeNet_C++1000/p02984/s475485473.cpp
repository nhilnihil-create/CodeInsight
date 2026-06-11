#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) {
cin>>A[i];
  }
  ll k=(N+1)/2;
  ll sum=0;
  ll s;
  if(k%2==0) {
s=1;
  }
  else {
s=-1;
  }
  ll t=s;

  
  for(ll i=0;i<k-1;i++) {
    sum+=A[i]*s;
    s*=-1;
  }
  
  for(ll i=N-1;i>=k;i--) {
sum+=A[i]*t;
    t*=-1;
  }
  
    
  ll x;
  if(k%2==0) {
x=(sum-A[k-1])/2;
  }
  else {
x=(A[k-1]-sum)/2;
  }

  cout<<2*x<<" ";
  for(ll i=1;i<N;i++) {
    x=A[i-1]-x;
    cout<<2*x<<" ";
  }
  cout<<endl;
}

  
 
  
  