#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,M;
  cin>>N>>M;
  ll total=0;
  vector<ll> A(N);
  
  for(ll i=0;i<N;i++) {
    cin>>A[i];
    total+=A[i];
  }
  ll count=0;
  for(ll  i=0;i<N;i++){
if(A[i]*4*M>=total) {
count++;
}
    
  }
  if(count>=M) {
cout<<"Yes"<<endl;
  }
  else {
cout<<"No"<<endl;
  }
}

  