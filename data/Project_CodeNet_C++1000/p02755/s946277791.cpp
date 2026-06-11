#include <bits/stdc++.h>
using namespace std;

void solve () {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 1000; i++) {
        int f = i * 8 / 100;
        int s = i * 10 / 100;
        if (f == a && b == s) {
            cout << i;
            return;
        }
    }
    cout << -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
