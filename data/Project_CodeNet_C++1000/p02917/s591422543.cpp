#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define vl vector<long long>

int main() {
    ll n; cin >> n;
    vl b(n-1);
    rep(i,n-1) cin >> b[i];

    ll ans = b[0] + b[n - 2];
    rep(i,n-2){
        ans += min(b[i],b[i + 1]);
    }
    cout << ans << endl;
}