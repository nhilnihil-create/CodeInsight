#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<double> vec(N);
  for(ll i=0;i<N;i++) {
cin>>vec[i];
  }
  sort(all(vec));
  double ans=(vec[0]+vec[1])/2;
  for(ll i=2;i<N;i++) {
ans=(ans+vec[i])/2;
  }
  
  
  cout<<fixed<<setprecision(8);
  cout<<ans<<endl;
}

    
    
    
      
      
      
      
      
 
      
      
      
    
    
    
    
    
    
    
    
    
