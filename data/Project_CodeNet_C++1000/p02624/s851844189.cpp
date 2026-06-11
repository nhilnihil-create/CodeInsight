#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N;
  cin>>N;
  ll ans=0;
  for(ll i=1;i<=N;i++) {
ll A=N/i;
    ans+=i*A*(A+1)/2;
  }
  cout<<ans<<endl;
}
  
  

  
  
  
  
  
  
  
  
  
  
  
  
  