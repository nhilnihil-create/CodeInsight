#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,X,Y;
  cin>>N>>X>>Y;
  map<ll,ll> S;
  
  for(ll i=1;i<=N-1;i++) {
for(ll j=i+1;j<=N;j++) {
  S[min(j-i,abs(i-X)+1+abs(Y-j))]++;
}
  }
  
  for(ll i=1;i<N;i++) {
cout<<S[i]<<endl;
  }
}
  

   


  
  
  
