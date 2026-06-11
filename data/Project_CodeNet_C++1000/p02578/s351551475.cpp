#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int m = 0;
    ll ans = 0;
    rep(i,n) {
        if (a[i] < m) {
            ans += m - a[i];
        }
        m = max(m, a[i]);
    }

    cout << ans << endl;
    
    return 0;
}