#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> v(1e6 + 1, 0);
    rep(i, n) {
        if (v[a[i]] >= 1) {
            v[a[i]]++;
            continue;
        }
        for (int j = a[i]; j <= 1e6; j+=a[i]) {
            v[j]++;
        }
    }
    int ans = 0;
    rep(i, n) {
        if (v[a[i]] <= 1) {
            ans++;
            //cout << a[i] << ' ';
        }
    }
    cout << ans << endl;
    return 0;
}
