#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll A,B,C,D;
  cin>>A>>B>>C>>D;
  ll c=B/C-A/C;
  ll X=C;
  ll Y=D;
  if(A%C==0) {
c++;
  }
  ll d=B/D-A/D;
  if(A%D==0) {
d++;
  }
 
  
  ll cd=1;
  ll K=min(C,D);
  for(ll i=2;i<=sqrt(K);i++) {
if(C%i==0&&D%i==0) {
while(C%i==0&&D%i==0) {
C/=i;
  D/=i;
  cd*=i;
}
}
    
    if(C%i==0) {
while(C%i==0) {
C/=i;
}
    }
    if(D%i==0) {
while(D%i==0) {
D/=i;
}
    }
  }
  if(D%C==0) {
cd*=C;
  }
  else if(C%D==0) {
cd*=D;
  }
  
  cd=cd*(X/cd)*(Y/cd);
  ll ans=B/cd-A/cd;
  if(A%cd==0) {
ans++;
  }
 
  
  cout<<B-A+1-c-d+ans<<endl;
}
  
  
  
  
  
  

  
  
