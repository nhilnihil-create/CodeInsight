#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
    ll n;
    cin >> n;
    vector<ll> b(n-1);
    rep(i,n-1) cin >> b[i];
    ll ans = b[0];
    rep(i,n-2) {
        ans += min(b[i], b[i+1]);
    }
    ans += b[n-2];
    cout << ans << endl;
    return 0;
}
