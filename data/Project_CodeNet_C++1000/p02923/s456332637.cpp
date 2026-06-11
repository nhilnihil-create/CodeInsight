#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    int ans = 0;
    int cnt = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (r < x) {
            ans = max (cnt, ans);
            cnt = 0;
        }
        else {
            cnt++;
        }
        r = x;
    }
    ans = max (cnt, ans);
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
