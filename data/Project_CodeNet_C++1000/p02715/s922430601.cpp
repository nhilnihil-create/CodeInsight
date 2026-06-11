# include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 3;

int n, k;
long long ar[N];

int bin_pow(int a, int n) {
    int ret = 1;
    while (n) {
        if (n & 1)
            ret = (ret * 1ll * a) % mod;
        a = (a * 1ll * a) % mod;
        n >>= 1;
    }
    return ret;
}

int main() {
    cin >> n >> k;

    long long ans = 0;
    for (int i = k; i >= 1; i--) {
        ar[i] = bin_pow(k / i, n);
        for (int j = i + i; j <= k; j += i)
            ar[i] = (ar[i] - ar[j] + mod) % mod;
        ans = (ans + (ar[i] * i)) % mod;
    }

    cout << ans << endl;
}
