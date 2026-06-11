#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int power(ll a, ll b){
  ll res=1;
  while(b>0){
   if(b & 1) res=res*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  
  return res;
  
}

int main(){
  ll n,k; 
  cin >> n >> k;
  
  for(int i=1; i<=k; i++){
    if(n-k+1<i){
     cout << 0 << endl;
     continue;
    }
    
    ll ans=1;
    
    for(int j=1; j<=n-k+1; j++){
     ans*=j;
     ans%=mod;
   }
  
    for(int j=1; j<=i; j++){
     ans*=power(j,mod-2);
     ans%=mod;
   }
   
    for(int j=1; j<=n-k+1-i; j++){
      ans*=power(j,mod-2);
      ans%=mod;
    }
    
    for(int j=1; j<=k-1; j++){
      ans*=j;
      ans%=mod;
    }
    
    for(int j=1; j<=i-1; j++){
      ans*=power(j,mod-2);
      ans%=mod;
    }
    
    for(int j=1; j<=k-i; j++){
      ans*=power(j,mod-2);
      ans%=mod;
    }
    
    cout << ans << endl;
    
  }
  
}
