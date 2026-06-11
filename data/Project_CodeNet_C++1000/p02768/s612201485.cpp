#include <bits/stdc++.h>
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll modpow(ll b, ll i){
  ll s=1;
  while(i){
    if(i%2) s=(s*b)%MOD;
    b=(b*b)%MOD; i/=2;
  }
  return s;
}
int main(){
  int n,a,b; cin >>n >>a >>b;
  ll fa=1,ga=1,fb=1,gb=1;
  for(int i=0; i<a; i++){
    fa=(fa*(n-i))%MOD; ga=(ga*(a-i))%MOD;
  }
  for(int i=0; i<b; i++){
    fb=(fb*(n-i))%MOD; gb=(gb*(b-i))%MOD;
  }
  cout <<(((modpow(2,n)-fa*modpow(ga,MOD-2)-fb*modpow(gb,MOD-2)-1)%MOD)+MOD)%MOD;
return 0;}