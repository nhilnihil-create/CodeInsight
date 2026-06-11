#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
  cin>>N;
  vector<ll> P(N);
  vector<ll> Q(N);
  for(ll i=0;i<N;i++) {
cin>>P[i];
  }
  for(ll i=0;i<N;i++) {
cin>>Q[i];
  }
  vector<ll> vec(N);
  for(ll i=0;i<N;i++) {
vec[i]=i+1;
  }
  
 ll count=0;
  ll a,b;
  
  do {
    count++;
    bool A=true;
    bool B=true;
    for(ll i=0;i<N;i++) {
      if(vec[i]!=P[i]) {
A=false;
      }
      if(vec[i]!=Q[i]) {
B=false;
      }
    }
    if(A) {
a=count;
    }
    if(B) {
b=count;
    }
    
  } while(next_permutation(all(vec)));
  
  
  cout<<abs(a-b)<<endl;
}
      
      

  
  
  
  
  
  
  