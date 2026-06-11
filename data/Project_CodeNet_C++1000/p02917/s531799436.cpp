#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> B(N-1);
  for(ll i=0;i<N-1;i++) {
cin>>B[i];
  }
  ll ans=0;
  ans+=B[0]+B.back();
  for(ll i=1;i<=N-2;i++) {
    ans+=min(B[i-1],B[i]);
  }
  
  
  cout<<ans<<endl;
}

  