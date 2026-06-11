#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

//繰り返し二乗法
ll EX(ll x,ll n){
    if(n == 0) return 1;
    else if(n%2 == 1) return EX(x,n-1)*x%mod;
    else return EX(x*x%mod,n/2)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> bit(60,0);
    for(int j = 0; j < n; j++){
        for(int i = 0; i < 60; i++){
            if(a[j] & (1ll << i)) bit[i]++;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll now = 1;
        for(int j = 0; j < 60; j++){
            if(a[i] & (1ll << j)){
                bit[j]--;
                ans += now*(n-i-1-bit[j])%mod;
                ans %= mod;
            } else ans += now*bit[j]%mod;
            now *= 2;
            now %= mod;
        }
    }

    cout << (ans+mod)%mod << endl;

    return 0;
}