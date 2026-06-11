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
    ll count=1;
    for(ll j=0;j<A;j++) {
ans+=i*count;
      count++;
    }
  }
  
  cout<<ans<<endl;
}
  
  
  
  
