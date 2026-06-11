#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
string S,T;
  cin>>S>>T;
  ll N=S.size();
  ll ans=N;
  for(ll i=0;i<N;i++) {
if(S[i]==T[i]) {
ans--;
}
  }
  
  cout<<ans<<endl;
}
  
