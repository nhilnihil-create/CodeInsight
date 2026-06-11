#include<iostream>
#include <vector>
using namespace std;

#define ll long long

const ll MOD = 1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(ll i = 0; i < 61; i++){
        ll x = 0, y = 0;
        for(ll j = 0; j < n; j++){
            if( (a[j] & (1ll<<i)) ) x++;
            else y++;
        }
        ll tmp = (x*y)%MOD;
        tmp = (tmp * ((1ll<<i)%MOD))%MOD;
        ans = (ans + tmp)%MOD;
    }
    cout << ans;

}
