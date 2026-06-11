#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n; cin >> n;
    ll ans = 0;
    for(ll i = 1; i < n; i++) {
        for(ll j = 1; (i * j) < n; j++) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
