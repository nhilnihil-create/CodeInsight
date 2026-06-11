#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> H(N);
  for(ll i=0;i<N;i++) {
cin>>H[i];
  }
  
  ll ans=0;
  for(ll i=0;i<N-1;i++) {
  if(H[i]>=H[i+1]) {
ll count=1;
    for(ll j=i+1;j<N-1;j++) {
if(H[j]>=H[j+1]) {
count++;
}
   else {
i=j;
     break;
   }
     if(j==N-2) {
i=j;
     }
    }
    ans=max(ans,count);
  }
  }



cout<<ans<<endl;
}
    
    
    
      
      
      
      
      
 
      
      
      
    
    
    
    
    
    
    
    
    
