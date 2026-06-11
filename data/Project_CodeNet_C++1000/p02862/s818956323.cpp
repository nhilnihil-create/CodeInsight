#include <iostream>

using namespace std;
typedef long long ll;

const ll M = 1000000007;

ll kaiM(ll x){
  ll ans = 1;
  if(x == 0) return 1l; 
  for (ll i = 1; i <= x; i++){
    ans *= i;
    ans %= M;
  }
  return ans;
}

ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

int main(){
  int X, Y;
  cin >> X >> Y;
  int a, b;

  ll ans, p, q;
  a = ((2 * Y) / 3) - (X / 3);
  b = ((2 * X) / 3) - (Y / 3);

  if((X + Y)%3 == 0 && a >= 0 && b >= 0){
    p = kaiM(a);
    q = kaiM(b);
    ans = kaiM(a + b);
    ans = ans * mpow(p, M-2) % M;
    ans = ans * mpow(q, M-2) % M;
    printf("%lld\n", ans);
  }else{
    printf("0\n");
  }
}
