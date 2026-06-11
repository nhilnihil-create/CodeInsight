#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1 / a[i];
    }
    ans = 1 / ans;

    cout << ans << endl;
}