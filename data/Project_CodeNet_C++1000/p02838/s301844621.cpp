#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll mBit(ll n){
  return (1LL<<n)%mod;
}
int main(){
  ll n,a,i,j,B[61] = {},ans = 0;scanf("%lld",&n);
  for(i=0;i<n;i++){
    scanf("%lld",&a);
    for(j=0;j<=60;j++){
      B[j] += a%2;
      a >>= 1;
    }
  }
  for(i=0;i<=60;i++) ans = (ans+mBit(i)*B[i]%mod*(n-B[i])%mod)%mod;
  printf("%lld\n",ans);
}