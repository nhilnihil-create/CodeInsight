#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll K;
  cin>>K;
  string S;
  cin>>S;
  if(S.size()<=K) {
cout<<S<<endl;
  }
  else {
for(ll i=0;i<K;i++) {
cout<<S[i];
}
    cout<<"..."<<endl;
  }
  
}
