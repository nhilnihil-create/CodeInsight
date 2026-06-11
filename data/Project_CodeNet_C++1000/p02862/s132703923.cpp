#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
using namespace std;
using ll = long long;
 
const ll M = 1e9+7;// 10^9+7

ll mpow(ll x,ll y){// x^y(mod M)を計算
    ll ans = 1;
    while(y != 0){
        if(y&1){
            ans = ans * x % M;
        }
        x = x * x % M;
        y = y >> 1;
    }
    return ans % M;
}

ll comb(ll n,ll k){// nCk(mod 10^9+7)を計算 : nCk = n! * (k!)^(M-2) * ((n-k)!)^(M-2) (mod M)を使っている
    ll a=1,b=1,c=1;
    if(n == 0 && k == 0) return 1;
    if(n < k|| n < 0) return 0;
    for(ll i = 1;i <= n;++i){// n!を計算
        a = a * i % M;
    }
    for(ll i = 1;i <= k;++i){// k!を計算
        b = b * i % M;
    }
    for(ll i = 1;i <= (n-k);++i){// (n-k)!を計算
        c = c * i % M;
    }
    b = mpow(b,M-2);// (k!)^(M-2)を計算
    c = mpow(c,M-2);// ((n-k)!)^(M-2)を計算
    return (a * b) % M * c % M;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, y;
    cin >> x >> y;
    ll n = (x+y) / 3;
    if((x+y)%3 != 0){ //合計が3の倍数ではなかったら0
        cout << 0 << endl;
        return 0;
    }
    x -= n;
    y -= n;
    if(x < 0 || y < 0) { 
        cout << 0 << endl;
        return 0;
    }
    ll ans = comb(x+y,y)%M;
    cout << ans << endl;

    cout << endl;
    return 0;
}
