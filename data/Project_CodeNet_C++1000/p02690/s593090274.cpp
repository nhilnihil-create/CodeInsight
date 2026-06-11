#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll X;
  cin>>X;
  vector<ll> vec(0);
  for(ll i=0;i<=150;i++) {
    ll a=1;
    for(ll j=0;j<5;j++) {
a*=i;
    }
    vec.push_back(a);
  }
  
  
  for(ll i=0;i<=150;i++) {
    ll k=abs(X-vec[i]);
    ll index=lower_bound(all(vec),k)-vec.begin();
    if(vec[index]==k) {
if(X-vec[i]>=0) {
  cout<<i<<" "<<-1*index<<endl;
}
      else {
cout<<i<<" "<<index<<endl;
      }
      return 0;
    }
  }
}


  
  
  
  