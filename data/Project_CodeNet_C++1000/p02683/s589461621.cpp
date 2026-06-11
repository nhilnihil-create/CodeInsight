#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,M,X;
  cin>>N>>M>>X;
  vector<vector<ll>> A(N,vector<ll>(M+1));
  for(ll i=0;i<N;i++) {
for(ll j=0;j<M+1;j++) {
cin>>A[i][j];
}
  }
  ll min=0;
  for(ll tmp=1;tmp<(1<<N);tmp++) {
bitset<12> s(tmp);
    ll money=0;
    vector<ll> vec(M,0);
    for(ll i=0;i<N;i++) {
if(s.test(i)) {
   money+=A[i][0];
  for(ll j=0;j<M;j++) {
vec[j]+=A[i][j+1];
}
    }
    }
    
    bool g=true;
    for(ll i=0;i<M;i++) {
if(vec[i]<X) {
  g=false;
}
    }
    
    if(g) {
if(min==0||min>money) {
min=money;
}
    }
    
  }
  
  if(min==0) {
cout<<-1<<endl;
  }
  else {
cout<<min<<endl;
  }
}

  
  
  
  
  
  
  
  
  
  
  
  