#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll kabu = 0;
    ll ans = 1000;

    for (int i = 0; i < n; i++) {
        if (i == n-1) {
            ans += a[i] * kabu;
            cout << ans << endl;
        }
        if (a[i] < a[i+1]) {
            kabu += ans / a[i];
            ans -= a[i] * (ans / a[i]);
        } else { 
            ans += a[i] * kabu;
            kabu = 0;
        }   
    }

    return 0;
}