#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            ans += a[i-1]-a[i];
            a[i] = a[i-1];
        }
    }
    cout << ans << endl;
}
