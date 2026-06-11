#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<pair<ll, ll>> a(n);
    for(int i=0; i<n; i++) {
        ll x, l;
        cin >> x >> l;
        a[i].first = x + l;
        a[i].second = x - l;
    }
    sort(a.begin(),a.end());
    ll ans = 0, d = -1e9+7;
    for(int i=0; i<n; i++) {
        if(d <= a[i].second) {
            ans++;
            d = a[i].first;
        }
    }
    cout << ans << endl;
}