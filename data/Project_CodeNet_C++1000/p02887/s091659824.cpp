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
  for(ll i=0;i<N;i++) {
    
for(ll j=i+1;j<N;j++) {
if(S[i]!=S[j]) {
    i=j-1;
break;
  }
  if(j==N-1) {
i=j;
  }
}
    ans++;
    
  }
  cout<<ans<<endl;
}
  
