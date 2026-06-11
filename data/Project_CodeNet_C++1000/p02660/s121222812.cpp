#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<pair<ll,ll>> vec(0);
  for(ll i=2;i<=sqrt(N);i++) {
if(N%i==0) {
ll count=0;
  while(N%i==0) {
N/=i;
    count++;
  }
  vec.push_back(make_pair(i,count));
}
  }
  
  if(N>1) {
vec.push_back(make_pair(N,1));
  }
  
  ll ans=0;
   for(auto x:vec) {
     ll n=1;
     while(n*(n+1)/2<=x.second) {
n++;
     }
     ans+=n-1;
   }
  
  cout<<ans<<endl;
}

     
     
     
     
     
     
     
     
     
     
     
 