#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp  make_pair
#define pb  push_back
#define endl "\n"
#define rep(i,a,n) for(int i=a;i<n;i++)
void solve() {
    int d, t, s;
    cin >> d >> t >> s;
    if (d <= t * s) {
        cout << "Yes" << endl;
        return;
    }

    cout << "No" << endl;
    return;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

