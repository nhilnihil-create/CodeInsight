#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll L,R;
    cin >> L >> R;
    ll ans = 2018;
    for(ll i = L; i < min(L+2019,R); i++) {
        for(ll j = i+1; j <= min(L+2019,R); j++) {
            ans = min(ans,i*j%2019);
        }
    }
    cout << ans << endl;
}