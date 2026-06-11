#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    ll a,b,c;
    cin >> a >> b;
    if (b-a > 2500) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 10000;
    for(ll i = a; i <= b; i++) {
        for(ll j = i+1; j <= b; j++) {
            c = i*j%2019;
            ans = min(ans,c);
        }
    }
    cout << ans << endl;
    return 0;
}
