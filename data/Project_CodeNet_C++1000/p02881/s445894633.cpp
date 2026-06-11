#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
  cin>>N;
  ll ans=10000000000000;
  for(ll i=1;i<=sqrt(N);i++) {
    if(N%i==0) {
ans=min(ans,i+N/i);
    }
  }
    
cout<<ans-2<<endl;
}
 
    
    
    
    
    
    
    
    
  
  