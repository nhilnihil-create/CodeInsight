#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int k, q;
    cin >> k >> q;
    vector<ll> d(k);
    for (int i = 0; i < k; i++) cin >> d[i];
    
    ll dsum = 0;
    for (int i = 0; i < k; i++) dsum += d[i];
    
    for (int z = 0; z < q; z++) {
        ll n, x, m;
        cin >> n >> x >> m;
        vector<ll> e(k);
        ll esum = 0;
        for (int i = 0; i < k; i++) {
            e[i] = d[i]%m;
            esum += e[i];
        }
        ll t = x%m;
        t += esum * ((n-1) / (ll)k);
        for (int i = 0; i < (n-1)%k; i++) t += e[i];
        ll ans = n - 1 - (t/m);
        ans -= count(e.begin(), e.end(), 0) * ((n-1) / (ll)k);
        for (int i = 0; i < ((n-1)%k); i++) {
            if (e[i] == 0) ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
