#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,K;
  cin>>K>>N;
  vector<ll> A(N);
  
  for(ll i=0;i<N;i++) {
cin>>A[i];
  }
  ll m=0;
  for(ll i=0;i<N-1;i++) {
m=max(m,A[i+1]-A[i]);
  }
  m=max(m,K+A[0]-A[N-1]);
  cout<<K-m<<endl;
}
  