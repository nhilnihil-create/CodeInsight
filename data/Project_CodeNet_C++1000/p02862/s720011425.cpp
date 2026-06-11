#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 3000000000000000000; //3*10^18
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
 
int main(){
    ll X,Y;
    cin >> X >> Y;
    if( (X+Y) % 3 != 0 ){
        printf("0\n");
        return 0;
    }
    ll d = (X + Y) / 3;
    ll a = (2*X - Y) / 3;
    a = min(a, d-a);
    if( a < 0 ){
        printf("0\n"); return 0;
    }
    ll ans = 1;
    vector<ll> inv(a+1);
    inv[1] = 1;
    for (ll i = 2; i < a+1; i++) {
        inv[i] = MOD - (MOD / i) * inv.at(MOD % i) % MOD;
    }
 
    for (ll i = 0; i < a; i++) {
        ans = ans * (d-i) % MOD;
        ans = ans * inv.at(i+1) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}