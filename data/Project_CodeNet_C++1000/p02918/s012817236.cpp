#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,K;
  cin>>N>>K;
  string S;
  cin>>S;
  ll s=0;
  for(ll i=0;i<N-1;i++) {
    if(S[i]!=S[i+1]) {
s++;
    }
  }

  
  if(s==0) {
cout<<N-1<<endl;
    return 0;
  }
  else if(s==1) {
cout<<N-1<<endl;
    return 0;
  }
  
  
  if(s%2==0) {
if(s<=2*K) {
cout<<N-1<<endl;
  return 0;
}
    else {
cout<<N-1-(s-2*K)<<endl;
    }
  }
  
  else {
if(s+1<=2*K) {
cout<<N-1<<endl;
}
    else {
cout<<N-1-(s-2*K)<<endl;
    }
  }
}
  
  
  
  
  
  
  
