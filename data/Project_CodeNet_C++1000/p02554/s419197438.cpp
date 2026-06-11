#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll power(ll a,ll x){
  ll res=1;
  while(x){
    if(x&1) res=res*a%mod;
    a=a*a%mod;
    x>>=1;
  }
  return res;
}
int main(){
  ll n;cin>>n;
  ll ans=power(10,n)-2*power(9,n)+power(8,n);
  ans=(ans+2*mod)%mod;
  cout<<ans<<endl;
  return 0;
}