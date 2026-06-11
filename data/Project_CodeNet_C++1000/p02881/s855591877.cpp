#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long n;
    cin >> n;
    long long ans = n;
    long long x = ans;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans = min (ans, i + n / i);
        }
    }
    long long p = 2;
    if (ans == x) p = 1;
    cout << ans - p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
