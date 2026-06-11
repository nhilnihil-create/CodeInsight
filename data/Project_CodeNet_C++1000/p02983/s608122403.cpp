#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll L,R;
  cin>>L>>R;
 ll s=2019;
if(L/s!=R/s) {
cout<<0<<endl;
 
return 0;
}
  else if(L%s==0) {
cout<<0<<endl;
    
    return 0;
  }
  
  vector<ll> vec(R-L+1);
  ll A=L%s;
  
  for(ll i=0;i<R-L+1;i++) {
    vec[i]=A+i;
  }
  
  ll ans=2018;
  for(ll i=0;i<R-L;i++) {
for(ll j=i+1;j<R-L+1;j++) {
  ans=min(ans,(vec[i]*vec[j])%s);
}
  }
  
  cout<<ans<<endl;
}

    

  

  
  
