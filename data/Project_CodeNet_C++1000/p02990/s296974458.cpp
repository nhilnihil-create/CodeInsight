#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

ll mpow(ll x, ll n){ //x^n(mod mo) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % mo;
        x = x*x % mo;
        n = n >> 1;
    }
    return ans;
}

ll combi(ll n, ll r) {
  if(n < r || n < 0 || r < 0) return 0;
  if ( r * 2 > n ) r = n - r;
  ll dividend = 1;
  ll divisor  = 1;
  for ( ll i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    dividend %= mo;
    divisor  *= i;
    divisor %= mo;
  }
  return (dividend * mpow(divisor, mo-2)) % mo;
}

int main(){
    ll N, K;
    cin >> N >> K;
    for(ll i=1; i<=K; i++){
        /*if(i>N-K+1){
            cout << 0 << endl;
            continue;
        }*/
        cout << (combi(N-K+1, i)*combi(K-1,i-1)) % mo << endl;
    }

}
