#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e+9+7;

int main(){
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i = k; i <= n+1; i++){
        ans = (ans + i*(n-i+1) + 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}