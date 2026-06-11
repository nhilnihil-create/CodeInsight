#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), d(n + 1);
    
    rep(i, n) cin >> a[i];
    rep(i, n) {
        d[i + 1] = d[i] + a[i];
        d[i + 1] %= k;
    }
    map<ll, ll> mp;
    ll ans = 0;
    queue<ll> que;
    rep(r, n + 1) {
        ll t = (d[r] - r) % k;
        if (t < 0) t += k;
        ans += mp[t];
        mp[t]++;
        que.push(t);
        if (que.size() >= k) {
            mp[que.front()]--;
            que.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}