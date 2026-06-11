#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD=1e9+7;
ll modpow(ll b, ll i){
  ll s=1;
  while(i){
    if(i%2) s=(s*b)%MOD;
    b=(b*b)%MOD; i/=2;
  }
  return s;
}
ll nCr(ll n, ll r){
  ll m1=1,m2=1;
  for(int i=0; i<r; i++){
    m1=(m1*(n-i))%MOD; m2=(m2*(r-i))%MOD;
  }
  return (m1*modpow(m2,MOD-2))%MOD;
}
int main(){
  int n,a,b; cin >>n >>a >>b;  
  cout <<(modpow(2,n)-nCr(n,a)-nCr(n,b)-1+2*MOD)%MOD;
return 0;
}