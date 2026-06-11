#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}


int main() {
    ll l,r; cin >> l >> r;
    ll ans = 10000;
    if(r-l >= 2500){
        cout << 0;
        return 0;
    }else{
        for(ll i = l;i < r;i++){
            for(ll j = i+1;j <= r;j++){
                ans = min(ans,(i*j)%2019);
            }
        }
    }
    cout << ans;
}
