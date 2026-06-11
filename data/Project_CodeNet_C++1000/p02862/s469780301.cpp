#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

ll modpow(ll a, ll n) {
    if(n == 0) return 1 ;
    if(n == 1) return a % mod ;
    if(n % 2) return (a*modpow(a, n-1)) % mod ;
    ll t = modpow(a, n/2) ;
    return (t * t)% mod ;
}
int main (){
    ll x, y ;
    cin >> x >> y ;
    ll a, b ;
    b = 2*x - y ;
    if(b % 3 != 0 || b < 0){
        cout << 0 << endl ;
        return 0 ;
    }
    b /= 3 ;
    a = x - 2 * b ;
    if(a < 0){
        cout << 0 << endl ;
        return 0 ;
    }
    ll t = a + b ;
    ll sum = 1 ;
    for(int i = 1 ; i <= t ; i++){
        sum *= i ;
        sum %= mod ; 
    }
    ll ta = 1 ;
    ll tb = 1 ;
    for(int i = 1 ; i <= a; i++){
        ta *= i ;
        ta %= mod ;
    } 
    for(int i = 1; i <= b ; i++){
        tb *= i ;
        tb %= mod ;
    }
    ll ans = ((sum * modpow(ta, mod - 2))%mod* modpow(tb, mod - 2)) % mod ;
    cout << ans << endl ; 
}
