#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end() 

int main() {
 ll N;
  cin>>N;
  vector<vector<ll>> vec(9,vector<ll>(9));
  for(ll i=1;i<=N;i++) {
    string S=to_string(i);
    if(S.back()=='0') {
continue;
    }
    vec[S[0]-'0'-1][S.back()-'0'-1]++;
  }
  
  ll ans=0;
  for(ll i=0;i<9;i++) {
ans+=vec[i][i]*vec[i][i];
  }
  

  for(ll i=0;i<9;i++) {
for(ll j=0;j<9;j++) {
  if(i==j) {
continue;
  }
  ans+=vec[i][j]*vec[j][i];
}
  }
  
  
  cout<<ans<<endl;
}

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  
