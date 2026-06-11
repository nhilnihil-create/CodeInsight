#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1000000007;
const ll max_n = 1000001010;//n<=2*10~5より

ll pow_mod(ll x, ll n){ //x^n(mod M)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  ll x=1,y=1,z=1,w=1;
  for(ll i=0;i<a;i++){
    x *= (n-i);
    x %= M;
  }
  for(ll i=1;i<=a;i++){
    y *= i;
    y %= M;
  }
  for(ll i=0;i<b;i++){
    z *= n-i;
    z %= M;
  }
  for(ll i=1;i<=b;i++){
    w *= i;
    w %= M;
  }
  x = x * pow_mod(y,M-2) % M;
  z = z * pow_mod(w,M-2) % M;
  long long ans=1;
  while(n>0){
    if(n>=15){
      ans = ans * 32768;
      ans = ans % M;
      n -= 15;
    }else if(n>=10){
      ans = ans * 1024;
      ans = ans % M;
      n -= 10;
    }else{
      ans = ans * 2;
      ans = ans % M;
      n -= 1;
    }
    //cout << ans << endl;
  }
  ans -= x+z+1;
  ans %= M;
  if(ans < 0) cout << M + ans << endl;
  else cout << ans << endl;
}
