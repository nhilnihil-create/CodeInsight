#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

 // mod. m での a の逆元 a^{-1} を計算する
 ll modinv(ll a, ll m) {
     ll b = m, u = 1, v = 0;
     while (b) {
         ll t = a / b;
         a -= t * b; swap(a, b);
         u -= t * v; swap(u, v);
     }
     u %= m;
     if (u < 0) u += m;
     return u;
 }

int main(){
    ll x,y;
    cin >> x >> y;
    bool can = true;
    if((2*x-y)%3||2*x-y<0)
        can = false;
    if((2*y-x)%3||2*y-x<0)
        can = false;
    if(!can){
        cout << 0 << endl;
        return 0;
    }
    ll a = (2*y-x)/3;
    ll b = (2*x-y)/3;
    // cout << a << endl;
    // cout << b << endl;
    ll s=1,t=1,u=1;
    for(int i=1;i<=a;i++){
        t*=i;
        t%=MOD;
    }
    for(int i=1;i<=b;i++){
        u*=i;
        u%=MOD;
    }
    for(int i=1;i<=a+b;i++){
        s*=i;
        s%=MOD;
    }
    ll ans = s * modinv(t,MOD) % MOD * modinv(u,MOD) % MOD;
    cout << ans << endl;
}