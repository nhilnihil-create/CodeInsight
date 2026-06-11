#include<bits/stdc++.h>

using namespace std;

#define int long long

int ans;

void oks(int x, int n) {
    if (x == 1) {
        n--;
        for (int s = 1; s * s <= n; ++s) {
            if (n % s == 0) {
                if (s != 1) ans++;
                if (s * s != n) ans++;
            }        
        }
        return;
    }
    while (n % x == 0) n /= x;
    ans += ((n - 1) % x == 0);
}

main() {
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            oks(i, n);
            if (i * i != n) oks(n / i, n);
        }
    }
    cout << ans << '\n';
}