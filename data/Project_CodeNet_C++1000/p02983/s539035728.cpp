#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 2019;

int main() {
    ll l, r;
    cin >> l >> r;
    ll ans = mod;
    if (r-l+1<mod) for (ll i = l; i <= r-1; i++) for (ll j = i+1; j <= r; j++) ans = min(ans,((i%mod)*(j%mod))%mod);
    else ans = 0;
    cout << ans << endl;
    return 0;
}
