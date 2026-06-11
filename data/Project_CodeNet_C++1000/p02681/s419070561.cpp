#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S,T;
  cin>>S>>T;
  bool a=true;
  for(ll i=0;i<S.size();i++) {
if(S[i]!=T[i]) {
a=false;
}
  }
  if(a) {
cout<<"Yes"<<endl;
  }
  else {
cout<<"No"<<endl;
  }
}
 