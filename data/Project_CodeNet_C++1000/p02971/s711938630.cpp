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
  pair<ll,ll>  mas;
  pair<ll,ll> ma;
  for(ll i=0;i<N;i++) {
if(A[i]>mas.first) {
mas.first=A[i];
  mas.second=i;
}
    else if(ma.first<A[i]) {
ma.first=A[i];
      ma.second=i;
    }
  }
  
  for(ll i=0;i<N;i++) {
if(A[i]==mas.first&&i==mas.second) {
cout<<ma.first<<endl;
}
    else {
cout<<mas.first<<endl;
    }
  }
}
  
  

  
  
