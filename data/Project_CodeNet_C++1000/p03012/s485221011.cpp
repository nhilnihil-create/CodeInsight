#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N;
  cin>>N;
 ll total=0;
 vector<ll> W(N);
  for(ll i=0;i<N;i++) {
cin>>W[i];
    total+=W[i];
  }
  ll i=0;
  ll k=0;
  while(total>k) {
    k+=W[i];
    total-=W[i];
    i++;
  }
  i--;
  
  ll ans=min(k-total,total+W[i]-k+W[i]);
  cout<<ans<<endl;
}
  
  

  
  
