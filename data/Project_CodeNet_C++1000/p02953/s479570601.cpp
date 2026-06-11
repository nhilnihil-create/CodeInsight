#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mx = max (mx, x);
        if (mx > x  && mx - x > 1) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
