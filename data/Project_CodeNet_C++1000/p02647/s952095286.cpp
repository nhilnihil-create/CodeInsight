/**
*    created: 13.06.2020 21:08:42
**/
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(ki, k) {
        vector<int> b(n+1);
        rep(i,n) {
            int l = max(0, i-a[i]);
            int r = min(i+a[i]+1, n);
            b[l]++;
            b[r]--;
        }
        rep(i,n) b[i+1] += b[i];
        b.pop_back();
        if (a == b) break;
        a = b;
    }
    rep(i,n) cout << a[i] << endl;
    return 0;
}