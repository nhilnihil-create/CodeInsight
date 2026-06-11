#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S;
  cin>>S;
 ll N=S.size();
  vector<ll> vec(N);
  ll k=1;
  for(ll i=0;i<N;i++) {
    vec[i]=(S[N-1-i]-'0')*k%2019;
    k*=10;
    k%=2019;
  }
  
  vector<ll> R(N);
  ll sum=0;
  for(ll i=0;i<N;i++) {
    sum+=vec[i];
    sum%=2019;
    R[i]=sum;
  }
  
 
  
  map<ll,ll> W;
  for(ll i=0;i<N;i++) {
W[R[i]]++;
  }
  ll ans=0;
  for(auto x:W) {
    ans+=x.second*(x.second-1)/2;
    if(x.first==0) {
ans+=x.second;
    }
  }
  
  cout<<ans<<endl;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

  
