#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

int p(int a, int b) {
    int res = 1;
    while(b > 0) {
        if (b&1) res = res * a % mod;
        a = a * a % mod;;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = p(10, n) - p(9, n) - p(9, n) + p(8, n); ans %= mod; ans = (ans + mod) % mod;
    cout << ans << endl;
}