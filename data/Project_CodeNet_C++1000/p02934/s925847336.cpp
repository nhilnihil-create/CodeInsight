#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
 vector<ll> A(N);
  for(ll i=0;i<N;i++) {
cin>>A[i];
  }
  
double t=1;
  for(ll x:A) {
t*=x;
  }
  
double k=0;
  
  for(ll x:A) {
k+=t/x;
  }
  
  cout<<fixed<<setprecision(10);
  cout<<t/k<<endl;
}
  
