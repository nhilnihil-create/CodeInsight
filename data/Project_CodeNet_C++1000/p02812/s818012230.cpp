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
  for(ll i=0;i<N-2;i++) {
if(S[i]=='A') {
if(S[i+1]=='B'&&S[i+2]=='C') {
ans++;
}
}
  }
  
  
  cout<<ans<<endl;
}
  