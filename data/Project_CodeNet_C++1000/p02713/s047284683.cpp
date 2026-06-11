#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int mod = 1e9+7;

int gcd(int a, int b) { // aとbの最大公約数（ユークリッドの互除法）
    if (b == 0) return a;
    return gcd(b, a % b);
}

int n; // 変数

int main() {
// input
    cin >> n;
// solve
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans += gcd(gcd(i, j), k);
            }
        }
    }
// output
    cout << ans << "\n";
}