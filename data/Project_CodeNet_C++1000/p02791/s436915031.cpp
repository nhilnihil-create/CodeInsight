#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int curmin = 1e9;
    rep(i, n) {
        curmin = min(curmin, a[i]);
        if (a[i] == curmin) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}