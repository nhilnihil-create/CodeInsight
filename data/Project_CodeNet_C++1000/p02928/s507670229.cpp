#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pll = pair<long long int,long long int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
ll l=1000000007;

int main() {
  ll n,k; cin>>n>>k;
  vector<ll> v(n);
  rep(i,n){
    cin>>v[i];
  }
  ll ans=0;ll a=0,d=0;
  rep(i,n){
    
    rep(j,n){
      if(v[i]>v[j]){
        d++;
        if(j>i)a++;
      }
    }
    
  }
  ans+=(a*k)%l +( ( ((k-1)*k)/2) %l)*d; ans%=l;
   cout<<ans<<endl;
 
}