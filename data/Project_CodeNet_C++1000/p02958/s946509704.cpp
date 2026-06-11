#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> p(N);
  for(ll i=0;i<N;i++) {
cin>>p[i];
  }
  
  ll count=0;
  for(ll i=0;i<N;i++) {
if(p[i]!=i+1) {
swap(p[i],p[p[i]-1]) ;
  count++;
}
  }
  
  if(count<=1) {
cout<<"YES"<<endl;
  }
  else {
cout<<"NO"<<endl;
  }
}
     
     
