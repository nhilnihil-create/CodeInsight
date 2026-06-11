#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;
vector<ll> fac(1000001);
vector<ll> ifac(1000001);
const ll M = pow(10,9)+7;

ll mpow(ll x, ll n){ 
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ 
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

int main(){
  ll X,Y;
  cin >> X >> Y;
  ll ans=0;
  ll a,b;
  fac[0] = 1;
  ifac[0] = 1;
  a = (2*Y-X)/3;
  b = (2*X-Y)/3;
  for(ll i = 0; i<a+b; i++){
    fac[i+1] = fac[i]*(i+1) % M;
    ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M;
  }
  if((X+Y)%3!=0) ans=0;
  else{  
    //cout << a+b << " " << b << endl;
    if(a>=0 && b>=0) ans = comb(a+b,a)% M;
  }
  cout << ans << endl;
}
