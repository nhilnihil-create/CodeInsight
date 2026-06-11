#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, a[100], b[100], c[100], res;
int main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i < n; ++i)
        cin >> c[i];
    a[0] = n;
    for (int i = 1; i <= n; ++i) {
        res += b[a[i]];
        if (a[i] == a[i-1] + 1)
            res += c[a[i-1]];
    }
    cout << res;
    PLEC
}
