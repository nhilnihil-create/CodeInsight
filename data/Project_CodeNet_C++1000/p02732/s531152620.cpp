#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    map<int, ll> m;
    rep(i, n) m[a[i]]++;

    ll sum = 0;
    for (auto e : m) sum += e.second * (e.second - 1) / 2;

    rep(i, n) {
        int cnt = m[a[i]];
        ll ans = sum - (cnt - 1);
        cout << ans << endl;
    }
    return 0;
}
