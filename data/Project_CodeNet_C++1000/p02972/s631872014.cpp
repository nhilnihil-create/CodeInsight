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
  vector<ll> note(N,0);
  
  for(ll i=N;i>0;i--) {
    ll count=N/i;
    if(count==1) {
note[i-1]=A[i-1];
      if(A[i-1]==1) {
ans++;
      }
    continue;
    }
    ll sum=0;
    
    for(ll j=2;j<=count;j++) {
      sum+=note[i*j-1];
    }
    if(sum%2==A[i-1]) {
note[i-1]=0;
    }
    else {
note[i-1]=1;
      ans++;
    }
  }
  cout<<ans<<endl;
  for(ll i=0;i<N;i++) {
if(note[i]==1) {
cout<<i+1<<" ";
}
  }
  
  cout<<endl;
}

    


  
  
  