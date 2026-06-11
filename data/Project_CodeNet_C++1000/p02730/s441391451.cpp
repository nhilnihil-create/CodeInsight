#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 string S;
  cin>>S;
  string x=S;
  reverse(all(x));
  if(x!=S) {
cout<<"No"<<endl;
  return 0;
  }
  ll N=S.size()/2;
  for(ll i=0;i<N/2;i++) {
if(S[i]!=S[N-1-i]) {
cout<<"No"<<endl;
return 0;
}
  }
  
  
  cout<<"Yes"<<endl;
}
