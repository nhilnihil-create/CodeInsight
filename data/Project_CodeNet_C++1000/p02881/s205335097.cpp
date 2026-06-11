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
    ll n; cin >> n;
    ll ans = LLONG_MAX;
    for(ll i = 1;i * i <= n;i++){
        
        if(n % i == 0){
            ans = min(ans,n/i+i-2);
        }
    }
    cout << ans;
}
