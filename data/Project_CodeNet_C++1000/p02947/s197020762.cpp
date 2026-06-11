#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    map<string, ll> mp;
    rep(i,n) {
        string t;
        cin >> t;
        sort(t.begin(), t.end());
        ans += mp[t];
        mp[t]++;
    }
    cout << ans << endl;
}
