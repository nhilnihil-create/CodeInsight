#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;



int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> c(n);
    rep(i,n) {
        int at;
        cin >> at;
        at--;
        a[i] = at;
        c[at]++;
    }

    ll count = 0;
    rep(i,n) {
        if (c[i] < 2) continue;
        count += (c[i] * (c[i]-1)) / 2;
    }

    rep(i,n) {
        ll ans = count;
        if (c[a[i]] > 1) {
            ans -= c[a[i]]-1;
        }
        cout << ans << endl;
    }

    return 0;
}