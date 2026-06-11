#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    ll mx = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    }

    int loga = 0;

    while((1ll << loga) < mx) loga++;

    vector<int> bit(loga,0);
    for(int j = 0; j < n; j++){
        for(int i = 0; i < loga; i++){
            if(a[j] & (1ll << i)) bit[i]++;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll now = 1;
        for(int j = 0; j < loga; j++){
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