#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

vector<ll> P;
vector<ll> C;

set<ll> roop(ll x,ll &point) {
set<ll> S;
  S.insert(x);
  ll k=x;
  x=P[x-1];
  point+=C[x-1];
 
  while(x!=k) {
S.insert(x);
    x=P[x-1];
    point+=C[x-1];
  }
  return S;
}
 


int main() {
  ll N,K;
  cin>>N>>K;
 P=vector<ll>(N);
  for(ll i=0;i<N;i++) {
cin>>P[i];
  }
  C=vector<ll>(N);
  for(ll i=0;i<N;i++) {
    cin>>C[i];
  }

  
  
  
  
  
  vector<set<ll>> A(0);
  vector<vector<ll>> B(2,vector<ll>(0));
  
  vector<ll> ans(0);
 for(ll i=1;i<=N;i++) {
   ll index=-1;
 for(ll j=0;j<A.size();j++) {
   if(A[j].count(i)) {
index=j;
   }
 }
   if(index<0) {
     ll point=0;
   A.push_back(roop(i,point));
     B[0].push_back(A.back().size());
     B[1].push_back(point);
   index=A.size()-1;
   }
   
   
   
   
   ll place=P[i-1];
   ll point=C[place-1];
   ll m=point;
   if(K<B[0][index]) {
for(ll j=0;j<K-1;j++) {
  place=P[place-1];
  point+=C[place-1];
  m=max(m,point);
}
     
     ans.push_back(m);
   }
   
   else if(B[1][index]<=0) {
     for(ll j=0;j<B[0][index]-1;j++) {
         place=P[place-1];
  point+=C[place-1];
  m=max(m,point);
}
     ans.push_back(m);
   }
   
   else {
ll maxroop=K/(B[0][index])*B[1][index];
   place=i;
     point=0;
     m=0;
     for(ll j=0;j<K%B[0][index];j++) {
       place=P[place-1];
       point+=C[place-1];
       m=max(point,m);
     }
     maxroop+=m;
     
ll minroop=((K/(B[0][index]))-1)*B[1][index];
    
     if((K/(B[0][index]))-1==0) {
place=P[i-1];
point=C[place-1];
m=point;
for(ll j=0;j<B[0][index]-2;j++) {
   place=P[place-1];
       point+=C[place-1];
       m=max(point,m);
     }
     minroop+=m;
     }
     
     else {
        place=i;
     point=0;
     m=0;
     for(ll j=0;j<B[0][index];j++) {
       place=P[place-1];
       point+=C[place-1];
       m=max(point,m);
     }
     minroop+=m;
     }
     
     ans.push_back(max(maxroop,minroop));
   }
   
 }
  sort(all(ans));
  cout<<ans.back()<<endl;
}

 

       
     

     



  
  
 
   
     
     



  
  
  
  
  
  
  
  
  