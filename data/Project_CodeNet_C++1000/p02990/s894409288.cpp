#include<bits/stdc++.h>

using namespace std;

#define int long long
int mod = 1e9 + 7;
int f[4005], rev[4005];

int st(int x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) {
        int c = st(x, y / 2);
        return c * c % mod;
    }
    return x * st(x, y - 1) % mod;
}

int get(int n, int k) {
    return f[n + k - 1] * rev[n - 1] % mod * rev[k] % mod;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    f[0] = 1, rev[0] = 1;
    for (int i = 1; i <= 4000; ++i) f[i] = f[i - 1] * i % mod, rev[i] = st(f[i], mod - 2);
    for (int i = 1; i <= k; ++i) {
        int cnt = get(i, k - i);
        int cur = n - k - (i - 1);
        if (cur >= 0) {
            cout << cnt * get(i + 1, cur) % mod << '\n';
        }
        else cout << 0 << '\n';
    }
    return 0;
}

