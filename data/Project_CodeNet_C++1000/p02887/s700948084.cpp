#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char c = ' ';
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (c != s[i]) {
            ans++;
        }
        c = s[i];
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
