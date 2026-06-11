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
 ll max=H[0];

  for(ll i=1;i<N;i++) {
    if(max<H[i]) {
max=H[i];
      continue;
    }
    if(max>H[i]+1) {
cout<<"No"<<endl;
      return 0;
    }
  }
  
  
  cout<<"Yes"<<endl;
}
  
  

