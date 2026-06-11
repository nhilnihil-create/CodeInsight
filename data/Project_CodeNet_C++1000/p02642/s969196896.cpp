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
  sort(all(A));
 
 if(A[0]==1) {
   if(A[1]==1) {
cout<<0<<endl;
     return 0;
   }
   else {
cout<<1<<endl;
     return 0;
   }
 }
  ll ans=0;
  for(ll i=0;i<N;i++) {
if(i!=0&&A[i-1]==A[i]) {
  continue;
}
    if(i!=N-1&&A[i+1]==A[i]) {
continue;
    }
    
    bool a=true;
    for(ll j=2;j<=sqrt(A[i]);j++) {
if(A[i]%j==0) {
ll x=lower_bound(all(A),j)-A.begin();
  if(A[x]==j) {
    a=false;
    break;
  }
 ll y=lower_bound(all(A),A[i]/j)-A.begin();
  if(A[y]==A[i]/j) {
a=false;
    break;
  }
}
    }
    
    if(a) {
ans++;
    }
  }

  
  cout<<ans<<endl;
}


  
  
  
  