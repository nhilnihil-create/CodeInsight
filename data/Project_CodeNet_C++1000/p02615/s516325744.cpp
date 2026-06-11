#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    ans += a[0];
    int idx1 = 0, idx2 = 1;
    for (int i = 2; i < n; ++i) {
        if (i % 2 == 1) {
            ans += min(a[idx1], a[idx2]);
            idx1++;
            idx2++;
        } else {
            ans += min(a[idx1], a[idx2]);
        }
    }
    cout << ans << endl;
    return 0;
}