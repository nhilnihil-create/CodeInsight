#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n; cin>>n;
  ll ans=1e12;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0){ ans=min(i+n/i-2,ans); }
  }
  cout<<ans<<endl; 
  return 0;
}