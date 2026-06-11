#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ll n;cin>>n;
  ll ans=1e18;
 	for(ll i=1;i<=sqrt(n);i++){
    if(n%i!=0) continue;
    ll j=n/i;
    ans=min(ans,i+j-2);
  }
  cout<<ans<<endl;
}
