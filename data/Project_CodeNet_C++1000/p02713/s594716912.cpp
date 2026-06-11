#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    int k;
    cin >> k;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int f = 1; f <= k; f++) {
                ans += gcd(i, gcd(j, f));
            }
        }
    }
    cout << ans << endl;
}

