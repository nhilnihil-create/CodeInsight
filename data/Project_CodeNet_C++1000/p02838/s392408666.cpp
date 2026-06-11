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

 ll mod=1000000007;
  
  vector<vector<bool>> vec(61,vector<bool> (N,false));
  
  for(ll i=0;i<N;i++) {
bitset<61> S(A[i]);
   for(ll j=0;j<61;j++) {
if(S.test(j)) {
vec[j][i]=true;
}
   }
  }
  
  ll ans=0;
  ll k=1;
  
  for(ll i=0;i<61;i++) {
    ll count=0;
for(ll j=0;j<N;j++) {
  if(vec[i][j]) {
count++;
  }
}
    ll X=(N-count)*count;
    X%=mod;
    ans+=k*X;
    k*=2;
    k%=mod;
    ans%=mod;
    
  }
  cout<<ans<<endl;
}
    

  
  
  
  
  

  
