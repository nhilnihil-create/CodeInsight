#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll A,B;
  cin>>A>>B;
  vector<ll> As(0);
  vector<ll> Bs(0);
 if(A*50%4==0) {
As.push_back(A*50/4);
 }
  for(ll i=A*50/4+1;i<(A+1)*50/4;i++) {
As.push_back(i);
  }
  if((A+1)*50%4!=0) {
As.push_back((A+1)*50/4);
  }
  
  
  for(ll i=B*10;i<(B+1)*10;i++) {
Bs.push_back(i);
  }
  
  for(ll i=0;i<As.size();i++) {
for(ll j=0;j<Bs.size();j++) {
if(As[i]==Bs[j]) {
cout<<As[i]<<endl;
  return 0;
}
}
  }
  
  
  cout<<-1<<endl;
}
  
  
 