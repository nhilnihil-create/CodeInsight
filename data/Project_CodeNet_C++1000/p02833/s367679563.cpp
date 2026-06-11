#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n; cin >> n;
    long long ans = 0;
    if (n % 2 == 1) {
        cout << 0 << "\n";
    } else {
        long long cur = 10;
        while (cur <= n) {
            ans += n / cur;
            cur *= 5;
        }
        cout << ans << "\n";
    }
}