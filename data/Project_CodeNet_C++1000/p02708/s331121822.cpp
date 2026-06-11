#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N,K;
  cin>>N>>K;
  ll ans=0;
  for(ll i=K;i<=N+1;i++) {
    ans+=i*(2*N-i+1)/2-i*(i-1)/2+1;
    ans%=1000000007;
  }
  cout<<ans<<endl;
}
    

  
  
  
