#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  string S;
  cin>>S;
  ll ans=0;
  ll red=0;
  for(ll i=0;i<N;i++) {
    if(S[i]=='W') {
for(ll j=red;j<N-i-1;j++) {
 if( S[N-1-j]=='R') {
ans++;
   red=j+1;
   break;
 }
  if(j==N-i-2) {
red=j+1;
  }
}
      if(red==N-i-1) {
break;
      }
     
    
    }
  }
  
  cout<<ans<<endl;
}
   
  
  
  
  
  
  
  
  
  
  
  
