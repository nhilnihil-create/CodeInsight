#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp  make_pair
#define pb  push_back
#define endl "\n"
#define rep(i,a,n) for(int i=a;i<n;i++)
void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int m1 = 0;
    rep(i, 0, n - m + 1) {
        int j = i, k = 0, m2 = m, c = 0;
        while (m2--) {
            if (s[j] == t[k]) {
                c++;
            }
            j++;
            k++;
        }
        m1 = max(m1, c);
    }
    cout << m - m1 << endl;
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

