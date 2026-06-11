#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001;

int main() {
    int n; cin >> n;
    ll k; cin >> k;
    ll a[n];
    rep(i,n) {
        cin >> a[i];
    }
    ll b[n+1]; b[0] = 0;
    rep(i,n) {
        b[i+1] = (b[i]+a[i])%k;
    }
    ll c[n+1];
    ll x = k;
    while (x < 1000000) {
        x *= 2;
    }
    rep(i,n+1) {
        c[i] = (b[i]+x-i)%k;
    }
    int kk = (int)min(k, (ll)n+5);
    map<ll, ll> mp;
    ll ans = 0;
    rep(i,n+1) {
        if (i-k >= 0) {
            mp[c[i-k]]--;
        }
        ans += mp[c[i]];
        mp[c[i]]++;
        
    } 

    cout << ans << endl;
    return 0;
}
