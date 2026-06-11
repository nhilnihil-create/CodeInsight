#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i = k - 1; i <= n; i++){
        ll mn = (i * (i + 1) / 2), mx = (n * (n + 1) / 2) - (n - i - 1) * (n - i) / 2;
        ans = (ans + (mx - mn + 1)) % mod;
    }
    cout << ans;
    return 0;
}


